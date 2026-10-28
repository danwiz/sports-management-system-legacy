#include "sms/csv_support.hpp"
#include <charconv>
#include <fstream>
#include <set>
#include <stdexcept>

namespace sms::csv {
std::string escape(const std::string& value) {
    if (value.find_first_of(",\"\n\r") == std::string::npos) return value;
    std::string out = "\"";
    for (char c : value) out += c == '"' ? "\"\"" : std::string(1, c);
    return out + '"';
}
std::vector<std::string> parse_line(const std::string& line) {
    std::vector<std::string> fields;
    std::string value;
    bool quoted=false, closed=false;
    for (std::size_t i=0; i<line.size(); ++i) {
        char c=line[i];
        if (quoted) {
            if (c=='"' && i+1<line.size() && line[i+1]=='"') {value+='"'; ++i;}
            else if(c=='"') {quoted=false; closed=true;}
            else value+=c;
        } else if(c==',') {fields.push_back(value); value.clear(); closed=false;}
        else if(c=='"' && value.empty() && !closed) quoted=true;
        else if(c=='"' || closed) throw std::runtime_error("Malformed CSV quoting");
        else value+=c;
    }
    if(quoted) throw std::runtime_error("Unterminated CSV field");
    fields.push_back(value);
    return fields;
}
std::vector<std::vector<std::string>> read_rows(const std::filesystem::path& path,
                                              std::size_t width, const std::string& header) {
    if(!std::filesystem::exists(path)) return {};
    std::ifstream in(path);
    if(!in) throw std::runtime_error("Cannot read CSV: " + path.string());
    std::vector<std::vector<std::string>> rows;
    std::set<std::string> ids;
    std::string line, record;
    bool first=true, quoted=false;
    while(std::getline(in,line)) {
        if(!line.empty() && line.back()=='\r') line.pop_back();
        if(record.empty() && line.empty()) continue;
        if(!record.empty()) record+='\n';
        record+=line;
        for(char c:line) if(c=='"') quoted=!quoted;
        if(quoted) continue;
        if(first && !header.empty() && record==header) {first=false; record.clear(); continue;}
        first=false;
        auto fields=parse_line(record);
        if(fields.size()!=width || fields[0].empty() || !ids.insert(fields[0]).second)
            throw std::runtime_error("Invalid CSV row or duplicate identifier: " + path.string());
        rows.push_back(std::move(fields)); record.clear();
    }
    if(in.bad() || quoted || !record.empty()) throw std::runtime_error("Incomplete CSV: " + path.string());
    return rows;
}
int integer(const std::string& text) {
    int value=0;
    auto [end,error]=std::from_chars(text.data(),text.data()+text.size(),value);
    if(error!=std::errc{} || end!=text.data()+text.size()) throw std::runtime_error("Invalid CSV integer");
    return value;
}
bool replace_file(const std::filesystem::path& temp,const std::filesystem::path& target) {
    std::error_code ec;
    std::filesystem::rename(temp,target,ec);
    if(!ec) return true;
    if(!std::filesystem::is_regular_file(target)) return false;
    auto previous=target; previous+=".previous";
    if(std::filesystem::exists(previous)) return false;
    ec.clear(); std::filesystem::rename(target,previous,ec);
    if(ec) return false;
    std::filesystem::rename(temp,target,ec);
    if(ec) { std::error_code rollback; std::filesystem::rename(previous,target,rollback); return false; }
    std::filesystem::remove(previous,ec);
    return true;
}
}

#include "sms/csv_member_repository.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>

namespace sms {
namespace {

std::string escape_csv(const std::string& value) {
    if (value.find_first_of(",\"\n\r") == std::string::npos) {
        return value;
    }
    std::string escaped = "\"";
    for (char ch : value) {
        if (ch == '"') {
            escaped += "\"\"";
        } else {
            escaped += ch;
        }
    }
    escaped += '"';
    return escaped;
}

std::vector<std::string> parse_csv_line(const std::string& line) {
    std::vector<std::string> fields;
    std::string current;
    bool quoted = false;

    for (std::size_t i = 0; i < line.size(); ++i) {
        const char ch = line[i];
        if (quoted) {
            if (ch == '"' && i + 1 < line.size() && line[i + 1] == '"') {
                current += '"';
                ++i;
            } else if (ch == '"') {
                quoted = false;
            } else {
                current += ch;
            }
        } else if (ch == '"') {
            quoted = true;
        } else if (ch == ',') {
            fields.push_back(current);
            current.clear();
        } else {
            current += ch;
        }
    }
    fields.push_back(current);
    return fields;
}

}  // namespace

CsvMemberRepository::CsvMemberRepository(std::filesystem::path file_path)
    : file_path_(std::move(file_path)) {}

bool CsvMemberRepository::add(Member member) {
    if (member.id.empty()) {
        return false;
    }
    auto members = load();
    if (std::ranges::any_of(members, [&](const Member& item) { return item.id == member.id; })) {
        return false;
    }
    members.push_back(std::move(member));
    return save(members);
}

bool CsvMemberRepository::update(const Member& member) {
    auto members = load();
    const auto it = std::ranges::find_if(members, [&](const Member& item) { return item.id == member.id; });
    if (it == members.end()) {
        return false;
    }
    *it = member;
    return save(members);
}

bool CsvMemberRepository::remove(const std::string& id) {
    auto members = load();
    const auto original_size = members.size();
    std::erase_if(members, [&](const Member& item) { return item.id == id; });
    return members.size() != original_size && save(members);
}

std::optional<Member> CsvMemberRepository::find(const std::string& id) const {
    const auto members = load();
    const auto it = std::ranges::find_if(members, [&](const Member& item) { return item.id == id; });
    if (it == members.end()) {
        return std::nullopt;
    }
    return *it;
}

std::vector<Member> CsvMemberRepository::list() const {
    return load();
}

std::vector<Member> CsvMemberRepository::load() const {
    std::ifstream input(file_path_);
    if (!input) {
        return {};
    }

    std::vector<Member> members;
    std::string line;
    bool first_line = true;
    while (std::getline(input, line)) {
        if (first_line) {
            first_line = false;
            if (line == "id,first_name,last_name,date_of_birth,team_code") {
                continue;
            }
        }
        if (line.empty()) {
            continue;
        }
        const auto fields = parse_csv_line(line);
        if (fields.size() != 5 || fields[0].empty()) {
            continue;
        }
        members.push_back({fields[0], fields[1], fields[2], fields[3], fields[4]});
    }
    return members;
}

bool CsvMemberRepository::save(const std::vector<Member>& members) const {
    std::error_code error;
    if (file_path_.has_parent_path()) {
        std::filesystem::create_directories(file_path_.parent_path(), error);
        if (error) {
            return false;
        }
    }

    const auto temporary = file_path_.string() + ".tmp";
    std::ofstream output(temporary, std::ios::trunc);
    if (!output) {
        return false;
    }
    output << "id,first_name,last_name,date_of_birth,team_code\n";
    for (const auto& member : members) {
        output << escape_csv(member.id) << ','
               << escape_csv(member.first_name) << ','
               << escape_csv(member.last_name) << ','
               << escape_csv(member.date_of_birth) << ','
               << escape_csv(member.team_code) << '\n';
    }
    output.close();
    if (!output) {
        std::filesystem::remove(temporary, error);
        return false;
    }

    std::filesystem::remove(file_path_, error);
    error.clear();
    std::filesystem::rename(temporary, file_path_, error);
    return !error;
}

}  // namespace sms

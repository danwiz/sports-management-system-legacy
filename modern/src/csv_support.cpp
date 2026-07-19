#include "sms/csv_support.hpp"

namespace sms::csv {

std::string escape(const std::string& value) {
    if (value.find_first_of(",\"\n\r") == std::string::npos) {
        return value;
    }
    std::string escaped = "\"";
    for (const char ch : value) {
        escaped += (ch == '"') ? "\"\"" : std::string(1, ch);
    }
    escaped += '"';
    return escaped;
}

std::vector<std::string> parse_line(const std::string& line) {
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

}  // namespace sms::csv

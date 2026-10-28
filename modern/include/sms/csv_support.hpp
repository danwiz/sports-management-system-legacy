#pragma once

#include <string>
#include <filesystem>
#include <vector>

namespace sms::csv {

std::string escape(const std::string& value);
std::vector<std::string> parse_line(const std::string& line);

std::vector<std::vector<std::string>> read_rows(const std::filesystem::path&, std::size_t, const std::string&);
int integer(const std::string&);
bool replace_file(const std::filesystem::path&, const std::filesystem::path&);

}  // namespace sms::csv

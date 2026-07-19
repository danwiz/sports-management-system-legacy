#pragma once

#include <string>
#include <vector>

namespace sms::csv {

std::string escape(const std::string& value);
std::vector<std::string> parse_line(const std::string& line);

}  // namespace sms::csv

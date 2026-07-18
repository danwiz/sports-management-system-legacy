#pragma once

#include <string>

namespace sms {

struct Member {
    std::string id;
    std::string first_name;
    std::string last_name;
    std::string date_of_birth;
    std::string team_code;
};

}  // namespace sms

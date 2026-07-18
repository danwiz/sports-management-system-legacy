#pragma once

#include <string>
#include <vector>
#include "sms/member.hpp"

namespace sms {

struct Team {
    std::string code;
    std::string name;
    std::string sport;
    std::vector<Member> members;
};

}  // namespace sms

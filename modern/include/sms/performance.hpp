#pragma once
#include <string>
namespace sms {
struct Performance {
    std::string id;
    std::string match_id;
    std::string member_id;
    std::string sport;
    int primary{0};
    int secondary{0};
    int tertiary{0};
};
}

#pragma once

#include <string>

namespace sms {

struct Match {
    std::string id;
    std::string sport;
    std::string home_team_code;
    std::string away_team_code;
    std::string scheduled_at;
    std::string venue;
    int home_score{0};
    int away_score{0};
};

}  // namespace sms

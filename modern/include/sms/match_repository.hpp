#pragma once

#include <optional>
#include <string>
#include <vector>
#include "sms/match.hpp"

namespace sms {

class MatchRepository {
public:
    virtual ~MatchRepository() = default;
    virtual bool add(Match match) = 0;
    virtual bool update(const Match& match) = 0;
    virtual bool remove(const std::string& id) = 0;
    virtual std::optional<Match> find(const std::string& id) const = 0;
    virtual std::vector<Match> list() const = 0;
};

}  // namespace sms

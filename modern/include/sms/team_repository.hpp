#pragma once

#include <optional>
#include <string>
#include <vector>
#include "sms/team.hpp"

namespace sms {

class TeamRepository {
public:
    virtual ~TeamRepository() = default;
    virtual bool add(Team team) = 0;
    virtual bool update(const Team& team) = 0;
    virtual bool remove(const std::string& code) = 0;
    virtual std::optional<Team> find(const std::string& code) const = 0;
    virtual std::vector<Team> list() const = 0;
};

}  // namespace sms

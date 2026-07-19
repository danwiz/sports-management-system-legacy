#pragma once

#include <unordered_map>
#include "sms/team_repository.hpp"

namespace sms {

class InMemoryTeamRepository final : public TeamRepository {
public:
    bool add(Team team) override;
    bool update(const Team& team) override;
    bool remove(const std::string& code) override;
    std::optional<Team> find(const std::string& code) const override;
    std::vector<Team> list() const override;

private:
    std::unordered_map<std::string, Team> teams_;
};

}  // namespace sms

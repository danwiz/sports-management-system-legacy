#include "sms/in_memory_team_repository.hpp"
#include <algorithm>

namespace sms {

bool InMemoryTeamRepository::add(Team team) {
    if (team.code.empty() || teams_.contains(team.code)) return false;
    return teams_.emplace(team.code, std::move(team)).second;
}

bool InMemoryTeamRepository::update(const Team& team) {
    auto it = teams_.find(team.code);
    if (it == teams_.end()) return false;
    it->second = team;
    return true;
}

bool InMemoryTeamRepository::remove(const std::string& code) { return teams_.erase(code) == 1; }

std::optional<Team> InMemoryTeamRepository::find(const std::string& code) const {
    auto it = teams_.find(code);
    if (it == teams_.end()) return std::nullopt;
    return it->second;
}

std::vector<Team> InMemoryTeamRepository::list() const {
    std::vector<Team> result;
    result.reserve(teams_.size());
    for (const auto& [_, team] : teams_) result.push_back(team);
    std::sort(result.begin(), result.end(), [](const Team& a, const Team& b) { return a.code < b.code; });
    return result;
}

}  // namespace sms

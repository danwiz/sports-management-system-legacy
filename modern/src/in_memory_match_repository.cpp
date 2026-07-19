#include "sms/in_memory_match_repository.hpp"
#include <algorithm>

namespace sms {

bool InMemoryMatchRepository::add(Match match) {
    if (match.id.empty() || matches_.contains(match.id)) return false;
    return matches_.emplace(match.id, std::move(match)).second;
}

bool InMemoryMatchRepository::update(const Match& match) {
    auto it = matches_.find(match.id);
    if (it == matches_.end()) return false;
    it->second = match;
    return true;
}

bool InMemoryMatchRepository::remove(const std::string& id) { return matches_.erase(id) == 1; }

std::optional<Match> InMemoryMatchRepository::find(const std::string& id) const {
    auto it = matches_.find(id);
    if (it == matches_.end()) return std::nullopt;
    return it->second;
}

std::vector<Match> InMemoryMatchRepository::list() const {
    std::vector<Match> result;
    result.reserve(matches_.size());
    for (const auto& [_, match] : matches_) result.push_back(match);
    std::sort(result.begin(), result.end(), [](const Match& a, const Match& b) { return a.id < b.id; });
    return result;
}

}  // namespace sms

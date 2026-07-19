#pragma once

#include <unordered_map>
#include "sms/match_repository.hpp"

namespace sms {

class InMemoryMatchRepository final : public MatchRepository {
public:
    bool add(Match match) override;
    bool update(const Match& match) override;
    bool remove(const std::string& id) override;
    std::optional<Match> find(const std::string& id) const override;
    std::vector<Match> list() const override;

private:
    std::unordered_map<std::string, Match> matches_;
};

}  // namespace sms

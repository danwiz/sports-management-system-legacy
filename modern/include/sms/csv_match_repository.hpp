#pragma once

#include <filesystem>
#include "sms/match_repository.hpp"

namespace sms {

class CsvMatchRepository final : public MatchRepository {
public:
    explicit CsvMatchRepository(std::filesystem::path file_path);
    bool add(Match match) override;
    bool update(const Match& match) override;
    bool remove(const std::string& id) override;
    std::optional<Match> find(const std::string& id) const override;
    std::vector<Match> list() const override;

private:
    std::filesystem::path file_path_;
    std::vector<Match> load() const;
    bool save(const std::vector<Match>& matches) const;
};

}  // namespace sms

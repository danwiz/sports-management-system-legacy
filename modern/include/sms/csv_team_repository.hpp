#pragma once

#include <filesystem>
#include "sms/team_repository.hpp"

namespace sms {

class CsvTeamRepository final : public TeamRepository {
public:
    explicit CsvTeamRepository(std::filesystem::path file_path);
    bool add(Team team) override;
    bool update(const Team& team) override;
    bool remove(const std::string& code) override;
    std::optional<Team> find(const std::string& code) const override;
    std::vector<Team> list() const override;

private:
    std::filesystem::path file_path_;
    std::vector<Team> load() const;
    bool save(const std::vector<Team>& teams) const;
};

}  // namespace sms

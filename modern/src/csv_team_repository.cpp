#include "sms/csv_team_repository.hpp"
#include "sms/csv_support.hpp"

#include <algorithm>
#include <fstream>
#include <ranges>
#include <utility>

namespace sms {

CsvTeamRepository::CsvTeamRepository(std::filesystem::path file_path) : file_path_(std::move(file_path)) {}

bool CsvTeamRepository::add(Team team) {
    if (team.code.empty()) return false;
    auto teams = load();
    if (std::ranges::any_of(teams, [&](const Team& item) { return item.code == team.code; })) return false;
    team.members.clear();
    teams.push_back(std::move(team));
    return save(teams);
}

bool CsvTeamRepository::update(const Team& team) {
    auto teams = load();
    const auto it = std::ranges::find_if(teams, [&](const Team& item) { return item.code == team.code; });
    if (it == teams.end()) return false;
    *it = {team.code, team.name, team.sport, {}};
    return save(teams);
}

bool CsvTeamRepository::remove(const std::string& code) {
    auto teams = load();
    const auto original = teams.size();
    std::erase_if(teams, [&](const Team& item) { return item.code == code; });
    return teams.size() != original && save(teams);
}

std::optional<Team> CsvTeamRepository::find(const std::string& code) const {
    const auto teams = load();
    const auto it = std::ranges::find_if(teams, [&](const Team& item) { return item.code == code; });
    return it == teams.end() ? std::nullopt : std::optional<Team>(*it);
}

std::vector<Team> CsvTeamRepository::list() const { return load(); }

std::vector<Team> CsvTeamRepository::load() const {
    std::ifstream input(file_path_);
    if (!input) return {};
    std::vector<Team> teams;
    std::string line;
    bool first = true;
    while (std::getline(input, line)) {
        if (first) { first = false; if (line == "code,name,sport") continue; }
        if (line.empty()) continue;
        const auto fields = csv::parse_line(line);
        if (fields.size() != 3 || fields[0].empty()) continue;
        teams.push_back({fields[0], fields[1], fields[2], {}});
    }
    std::ranges::sort(teams, {}, &Team::code);
    return teams;
}

bool CsvTeamRepository::save(const std::vector<Team>& teams) const {
    std::error_code error;
    if (file_path_.has_parent_path()) std::filesystem::create_directories(file_path_.parent_path(), error);
    if (error) return false;
    const auto temp = file_path_.string() + ".tmp";
    std::ofstream output(temp, std::ios::trunc);
    if (!output) return false;
    output << "code,name,sport\n";
    for (const auto& team : teams) {
        output << csv::escape(team.code) << ',' << csv::escape(team.name) << ',' << csv::escape(team.sport) << '\n';
    }
    output.close();
    if (!output) { std::filesystem::remove(temp, error); return false; }
    std::filesystem::remove(file_path_, error);
    error.clear();
    std::filesystem::rename(temp, file_path_, error);
    return !error;
}

}  // namespace sms

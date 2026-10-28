#include "sms/csv_match_repository.hpp"
#include "sms/csv_support.hpp"

#include <algorithm>
#include <charconv>
#include <fstream>
#include <ranges>
#include <utility>

namespace sms {
namespace {
bool parse_int(const std::string& text, int& result) {
    const auto [ptr, ec] = std::from_chars(text.data(), text.data() + text.size(), result);
    return ec == std::errc{} && ptr == text.data() + text.size();
}
}

CsvMatchRepository::CsvMatchRepository(std::filesystem::path file_path) : file_path_(std::move(file_path)) {}

bool CsvMatchRepository::add(Match match) {
    if (match.id.empty()) return false;
    auto matches = load();
    if (std::ranges::any_of(matches, [&](const Match& item) { return item.id == match.id; })) return false;
    matches.push_back(std::move(match));
    return save(matches);
}

bool CsvMatchRepository::update(const Match& match) {
    auto matches = load();
    const auto it = std::ranges::find_if(matches, [&](const Match& item) { return item.id == match.id; });
    if (it == matches.end()) return false;
    *it = match;
    return save(matches);
}

bool CsvMatchRepository::remove(const std::string& id) {
    auto matches = load();
    const auto original = matches.size();
    std::erase_if(matches, [&](const Match& item) { return item.id == id; });
    return matches.size() != original && save(matches);
}

std::optional<Match> CsvMatchRepository::find(const std::string& id) const {
    const auto matches = load();
    const auto it = std::ranges::find_if(matches, [&](const Match& item) { return item.id == id; });
    return it == matches.end() ? std::nullopt : std::optional<Match>(*it);
}

std::vector<Match> CsvMatchRepository::list() const { return load(); }

std::vector<Match> CsvMatchRepository::load() const {
    std::vector<Match> values;
    for(const auto& f:csv::read_rows(file_path_,8,"id,sport,home_team_code,away_team_code,scheduled_at,venue,home_score,away_score")) values.push_back({f[0],f[1],f[2],f[3],f[4],f[5],csv::integer(f[6]),csv::integer(f[7])});
    return values;
}

bool CsvMatchRepository::save(const std::vector<Match>& matches) const {
    std::error_code error;
    if (file_path_.has_parent_path()) std::filesystem::create_directories(file_path_.parent_path(), error);
    if (error) return false;
    const auto temp = file_path_.string() + ".tmp";
    std::ofstream output(temp, std::ios::trunc);
    if (!output) return false;
    output << "id,sport,home_team_code,away_team_code,scheduled_at,venue,home_score,away_score\n";
    for (const auto& match : matches) {
        output << csv::escape(match.id) << ',' << csv::escape(match.sport) << ','
               << csv::escape(match.home_team_code) << ',' << csv::escape(match.away_team_code) << ','
               << csv::escape(match.scheduled_at) << ',' << csv::escape(match.venue) << ','
               << match.home_score << ',' << match.away_score << '\n';
    }
    output.close();
    if (!output) { std::filesystem::remove(temp, error); return false; }
    return csv::replace_file(temp, file_path_);
}

}  // namespace sms

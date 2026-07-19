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
    std::ifstream input(file_path_);
    if (!input) return {};
    std::vector<Match> matches;
    std::string line;
    bool first = true;
    while (std::getline(input, line)) {
        if (first) { first = false; if (line == "id,sport,home_team_code,away_team_code,scheduled_at,venue,home_score,away_score") continue; }
        if (line.empty()) continue;
        const auto fields = csv::parse_line(line);
        if (fields.size() != 8 || fields[0].empty()) continue;
        int home_score = 0;
        int away_score = 0;
        if (!parse_int(fields[6], home_score) || !parse_int(fields[7], away_score)) continue;
        matches.push_back({fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], home_score, away_score});
    }
    std::ranges::sort(matches, {}, &Match::id);
    return matches;
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
    std::filesystem::remove(file_path_, error);
    error.clear();
    std::filesystem::rename(temp, file_path_, error);
    return !error;
}

}  // namespace sms

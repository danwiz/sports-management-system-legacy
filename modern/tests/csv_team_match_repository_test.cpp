#include <cassert>
#include <filesystem>
#include "sms/csv_match_repository.hpp"
#include "sms/csv_team_repository.hpp"

int main() {
    const auto root = std::filesystem::temp_directory_path() / "sms_csv_team_match_test";
    std::error_code error;
    std::filesystem::remove_all(root, error);

    {
        sms::CsvTeamRepository teams(root / "teams.csv");
        assert(teams.add({"SOC-A", "Alpha, United", "soccer", {}}));
        assert(teams.add({"SOC-B", "Beta \"Stars\"", "soccer", {}}));
        assert(!teams.add({"SOC-A", "Duplicate", "soccer", {}}));
        auto team = teams.find("SOC-A");
        assert(team && team->name == "Alpha, United");
        team->name = "Alpha Updated";
        assert(teams.update(*team));

        sms::CsvMatchRepository matches(root / "matches.csv");
        assert(matches.add({"M-1", "soccer", "SOC-A", "SOC-B", "2026-08-01 10:00", "Main, Field", 2, 1}));
        assert(!matches.add({"M-1", "soccer", "SOC-A", "SOC-B", "", "", 0, 0}));
        auto match = matches.find("M-1");
        assert(match && match->venue == "Main, Field");
        match->away_score = 2;
        assert(matches.update(*match));
    }

    {
        sms::CsvTeamRepository teams(root / "teams.csv");
        sms::CsvMatchRepository matches(root / "matches.csv");
        assert(teams.list().size() == 2);
        assert(teams.find("SOC-A")->name == "Alpha Updated");
        assert(matches.list().size() == 1);
        assert(matches.find("M-1")->away_score == 2);
        assert(matches.remove("M-1"));
        assert(teams.remove("SOC-B"));
    }

    std::filesystem::remove_all(root, error);
    return 0;
}

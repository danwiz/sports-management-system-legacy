#pragma once
#include <filesystem>
#include <optional>
#include <string>
#include <vector>
#include "sms/match_repository.hpp"
#include "sms/performance_repository.hpp"
#include "sms/repository.hpp"
#include "sms/team_repository.hpp"
namespace sms {
struct MvpResult { Member member; int score; };
struct TeamSummary { Team team; int members; int matches_played; int wins; int draws; int losses; int points_for; int points_against; };
class SportsService {
public:
    SportsService(MemberRepository& members, TeamRepository& teams, MatchRepository& matches,
                  PerformanceRepository* performances = nullptr)
        : members_(members), teams_(teams), matches_(matches), performances_(performances) {}
    bool add_member(Member member, std::string& error);
    bool update_member(Member member, std::string& error);
    bool remove_member(const std::string& id, std::string& error);
    bool add_team(Team team, std::string& error);
    bool update_team(Team team, std::string& error);
    bool add_match(Match match, std::string& error);
    bool update_match(Match match, std::string& error);
    bool remove_match(const std::string& id, std::string& error);
    bool add_performance(Performance performance, std::string& error);
    bool update_performance(Performance performance, std::string& error);
    bool remove_performance(const std::string& id, std::string& error);
    bool remove_team(const std::string& code, std::string& error);
    int performance_score(const Performance& performance) const;
    std::optional<MvpResult> mvp_for_sport(const std::string& sport) const;
    bool write_mvp_file(const std::filesystem::path& path, std::string& error) const;
    std::vector<Member> search_members(const std::string& query) const;
    std::vector<TeamSummary> team_summaries(const std::string& sport = {}) const;
    bool write_report_file(const std::filesystem::path& path, std::string& error) const;
    std::vector<std::string> audit_data_quality() const;
private:
    MemberRepository& members_; TeamRepository& teams_; MatchRepository& matches_; PerformanceRepository* performances_;
    bool validate_member(const Member& member, std::string& error) const;
    bool validate_team(const Team& team, std::string& error) const;
    bool validate_match(const Match& match, std::string& error) const;
    bool validate_performance(const Performance& performance, std::string& error) const;
};
}
#include <cassert>
#include <string>
#include "sms/in_memory_match_repository.hpp"
#include "sms/in_memory_member_repository.hpp"
#include "sms/in_memory_team_repository.hpp"
#include "sms/sports_service.hpp"

int main() {
    sms::InMemoryMemberRepository members;
    sms::InMemoryTeamRepository teams;
    sms::InMemoryMatchRepository matches;
    sms::SportsService service(members, teams, matches);
    std::string error;

    assert(service.add_team({"SOC-A", "Alpha", "soccer", {}}, error));
    assert(service.add_team({"SOC-B", "Beta", "soccer", {}}, error));
    assert(!service.add_team({"SOC-A", "Duplicate", "soccer", {}}, error));

    assert(!service.add_member({"P-1", "Ada", "Lovelace", "1815-12-10", "MISSING"}, error));
    assert(service.add_member({"P-1", "Ada", "Lovelace", "1815-12-10", "SOC-A"}, error));

    assert(!service.add_match({"M-0", "soccer", "SOC-A", "SOC-A", "2026-08-01", "Main", 0, 0}, error));
    assert(service.add_match({"M-1", "soccer", "SOC-A", "SOC-B", "2026-08-01", "Main", 2, 1}, error));
    assert(!service.remove_team("SOC-A", error));

    assert(matches.remove("M-1"));
    assert(members.remove("P-1"));
    assert(service.remove_team("SOC-A", error));
    return 0;
}

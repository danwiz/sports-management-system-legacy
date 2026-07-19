#include <algorithm>
#include <cassert>
#include <optional>
#include <string>
#include <vector>
#include "sms/in_memory_match_repository.hpp"
#include "sms/in_memory_member_repository.hpp"
#include "sms/in_memory_team_repository.hpp"
#include "sms/sports_service.hpp"

namespace {
class InMemoryPerformanceRepository final : public sms::PerformanceRepository {
public:
    bool add(sms::Performance performance) override {
        if (find(performance.id)) return false;
        values_.push_back(std::move(performance));
        return true;
    }
    bool update(const sms::Performance& performance) override {
        auto it = std::find_if(values_.begin(), values_.end(), [&](const auto& value) { return value.id == performance.id; });
        if (it == values_.end()) return false;
        *it = performance;
        return true;
    }
    bool remove(const std::string& id) override {
        auto it = std::find_if(values_.begin(), values_.end(), [&](const auto& value) { return value.id == id; });
        if (it == values_.end()) return false;
        values_.erase(it);
        return true;
    }
    std::optional<sms::Performance> find(const std::string& id) const override {
        auto it = std::find_if(values_.begin(), values_.end(), [&](const auto& value) { return value.id == id; });
        return it == values_.end() ? std::nullopt : std::optional<sms::Performance>(*it);
    }
    std::vector<sms::Performance> list() const override { return values_; }
private:
    std::vector<sms::Performance> values_;
};
}

int main() {
    sms::InMemoryMemberRepository members;
    sms::InMemoryTeamRepository teams;
    sms::InMemoryMatchRepository matches;
    InMemoryPerformanceRepository performances;
    sms::SportsService service(members, teams, matches, &performances);
    std::string error;

    assert(service.add_team({"SOC-A", "Alpha", "soccer", {}}, error));
    assert(service.add_team({"SOC-B", "Beta", "soccer", {}}, error));
    assert(!service.add_team({"SOC-A", "Duplicate", "soccer", {}}, error));

    assert(!service.add_member({"P-1", "Ada", "Lovelace", "1815-12-10", "MISSING"}, error));
    assert(service.add_member({"P-1", "Ada", "Lovelace", "1815-12-10", "SOC-A"}, error));

    assert(!service.add_match({"M-0", "soccer", "SOC-A", "SOC-A", "2026-08-01", "Main", 0, 0}, error));
    assert(service.add_match({"M-1", "soccer", "SOC-A", "SOC-B", "2026-08-01", "Main", 2, 1}, error));
    assert(!service.remove_team("SOC-A", error));

    assert(service.add_performance({"STAT-1", "M-1", "P-1", "soccer", 1, 1, 0}, error));
    assert(!service.remove_member("P-1", error));
    assert(members.find("P-1"));
    assert(!service.remove_match("M-1", error));
    assert(matches.find("M-1"));

    assert(!service.update_performance({"STAT-1", "M-1", "P-1", "netball", 1, 1, 0}, error));
    assert(performances.find("STAT-1")->sport == "soccer");
    assert(service.update_performance({"STAT-1", "M-1", "P-1", "soccer", 2, 1, 0}, error));
    assert(performances.find("STAT-1")->primary == 2);

    assert(service.remove_performance("STAT-1", error));
    assert(!performances.find("STAT-1"));
    assert(!service.remove_performance("STAT-1", error));

    assert(service.remove_match("M-1", error));
    assert(service.remove_member("P-1", error));
    assert(service.remove_team("SOC-A", error));
    return 0;
}
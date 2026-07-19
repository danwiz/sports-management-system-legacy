#include <filesystem>
#include <iostream>
#include <limits>
#include <string>

#include "sms/csv_match_repository.hpp"
#include "sms/csv_member_repository.hpp"
#include "sms/csv_performance_repository.hpp"
#include "sms/csv_team_repository.hpp"
#include "sms/data_management.hpp"
#include "sms/sports_service.hpp"

namespace {

std::string prompt(const std::string& label) {
    std::cout << label;
    std::string value;
    std::getline(std::cin, value);
    return value;
}

int prompt_int(const std::string& label) {
    while (true) {
        const auto value = prompt(label);
        try {
            std::size_t consumed = 0;
            const int result = std::stoi(value, &consumed);
            if (consumed == value.size()) return result;
        } catch (...) {
        }
        std::cout << "Please enter a valid whole number.\n";
    }
}

void list_teams(const sms::TeamRepository& teams) {
    const auto items = teams.list();
    if (items.empty()) { std::cout << "No teams recorded.\n"; return; }
    for (const auto& team : items) {
        std::cout << team.code << " | " << team.name << " | " << team.sport << '\n';
    }
}

void list_members(const sms::MemberRepository& members) {
    const auto items = members.list();
    if (items.empty()) { std::cout << "No members recorded.\n"; return; }
    for (const auto& member : items) {
        std::cout << member.id << " | " << member.first_name << ' ' << member.last_name
                  << " | DOB " << member.date_of_birth << " | team "
                  << (member.team_code.empty() ? "unassigned" : member.team_code) << '\n';
    }
}

void list_matches(const sms::MatchRepository& matches) {
    const auto items = matches.list();
    if (items.empty()) { std::cout << "No matches recorded.\n"; return; }
    for (const auto& match : items) {
        std::cout << match.id << " | " << match.sport << " | " << match.home_team_code
                  << ' ' << match.home_score << " - " << match.away_score << ' '
                  << match.away_team_code << " | " << match.scheduled_at << " | " << match.venue << '\n';
    }
}

void teams_menu(sms::SportsService& service, sms::TeamRepository& teams) {
    while (true) {
        std::cout << "\nTeams\n1. List teams\n2. Add team\n3. Delete team\n0. Back\n";
        const auto choice = prompt("Selection: ");
        if (choice == "0") return;
        if (choice == "1") { list_teams(teams); continue; }
        if (choice == "2") {
            sms::Team team{prompt("Team code: "), prompt("Team name: "), prompt("Sport: "), {}};
            std::string error;
            std::cout << (service.add_team(std::move(team), error) ? "Team added.\n" : "Unable to add team: " + error + "\n");
            continue;
        }
        if (choice == "3") {
            std::string error;
            const auto code = prompt("Team code to delete: ");
            std::cout << (service.remove_team(code, error) ? "Team deleted.\n" : "Unable to delete team: " + error + "\n");
            continue;
        }
        std::cout << "Unknown selection.\n";
    }
}

void members_menu(sms::SportsService& service, sms::MemberRepository& members) {
    while (true) {
        std::cout << "\nMembers\n1. List members\n2. Add member\n3. Edit member\n4. Delete member\n0. Back\n";
        const auto choice = prompt("Selection: ");
        if (choice == "0") return;
        if (choice == "1") { list_members(members); continue; }
        if (choice == "2") {
            sms::Member member{prompt("Member ID: "), prompt("First name: "), prompt("Last name: "),
                               prompt("Date of birth (YYYY-MM-DD): "), prompt("Team code (optional): ")};
            std::string error;
            std::cout << (service.add_member(std::move(member), error) ? "Member added.\n" : "Unable to add member: " + error + "\n");
            continue;
        }
        if (choice == "3") {
            const auto id = prompt("Member ID to edit: ");
            auto member = members.find(id);
            if (!member) { std::cout << "Member not found.\n"; continue; }
            const auto first = prompt("First name [" + member->first_name + "]: ");
            const auto last = prompt("Last name [" + member->last_name + "]: ");
            const auto dob = prompt("Date of birth [" + member->date_of_birth + "]: ");
            const auto team = prompt("Team code [" + member->team_code + "]: ");
            if (!first.empty()) member->first_name = first;
            if (!last.empty()) member->last_name = last;
            if (!dob.empty()) member->date_of_birth = dob;
            if (!team.empty()) member->team_code = team;
            std::string error; std::cout << (service.update_member(*member, error) ? "Member updated.\n" : "Unable to update member: " + error + "\n");
            continue;
        }
        if (choice == "4") {
            const auto id = prompt("Member ID to delete: ");
            std::string error;
            std::cout << (service.remove_member(id, error) ? "Member deleted.\n" : "Unable to delete member: " + error + "\n");
            continue;
        }
        std::cout << "Unknown selection.\n";
    }
}

void matches_menu(sms::SportsService& service, sms::MatchRepository& matches) {
    while (true) {
        std::cout << "\nMatches\n1. List matches\n2. Add match\n3. Edit score\n4. Delete match\n0. Back\n";
        const auto choice = prompt("Selection: ");
        if (choice == "0") return;
        if (choice == "1") { list_matches(matches); continue; }
        if (choice == "2") {
            sms::Match match{prompt("Match ID: "), prompt("Sport: "), prompt("Home team code: "),
                             prompt("Away team code: "), prompt("Scheduled date/time: "), prompt("Venue: "),
                             prompt_int("Home score: "), prompt_int("Away score: ")};
            std::string error;
            std::cout << (service.add_match(std::move(match), error) ? "Match added.\n" : "Unable to add match: " + error + "\n");
            continue;
        }
        if (choice == "3") {
            const auto id = prompt("Match ID to edit: ");
            auto match = matches.find(id);
            if (!match) { std::cout << "Match not found.\n"; continue; }
            match->home_score = prompt_int("Home score: ");
            match->away_score = prompt_int("Away score: ");
            std::string error; std::cout << (service.update_match(*match, error) ? "Score updated.\n" : "Unable to update score: " + error + "\n");
            continue;
        }
        if (choice == "4") {
            const auto id = prompt("Match ID to delete: ");
            std::string error;
            std::cout << (service.remove_match(id, error) ? "Match deleted.\n" : "Unable to delete match: " + error + "\n");
            continue;
        }
        std::cout << "Unknown selection.\n";
    }
}

void statistics_menu(sms::SportsService& service, sms::PerformanceRepository& performances) {
    while (true) {
        std::cout << "\nStatistics and MVP\n1. List statistics\n2. Add performance\n3. Edit performance\n4. Delete performance\n5. Show MVPs\n6. Write mvp.txt\n0. Back\n";
        const auto choice = prompt("Selection: ");
        if (choice == "0") return;
        if (choice == "1") {
            const auto items = performances.list();
            if (items.empty()) std::cout << "No statistics recorded.\n";
            for (const auto& item : items) std::cout << item.id << " | " << item.sport << " | member " << item.member_id << " | match " << item.match_id << " | " << item.primary << ", " << item.secondary << ", " << item.tertiary << " | score " << service.performance_score(item) << '\n';
            continue;
        }
        if (choice == "2") {
            sms::Performance item{prompt("Performance ID: "), prompt("Match ID: "), prompt("Member ID: "), prompt("Sport (soccer/netball/track): "), prompt_int("Primary statistic: "), prompt_int("Secondary statistic: "), prompt_int("Tertiary statistic: ")};
            std::string error; std::cout << (service.add_performance(std::move(item), error) ? "Performance added.\n" : "Unable to add performance: " + error + "\n"); continue;
        }
        if (choice == "3") {
            const auto id = prompt("Performance ID to edit: ");
            auto item = performances.find(id);
            if (!item) { std::cout << "Performance not found.\n"; continue; }
            const auto match_id = prompt("Match ID [" + item->match_id + "]: ");
            const auto member_id = prompt("Member ID [" + item->member_id + "]: ");
            const auto sport = prompt("Sport [" + item->sport + "]: ");
            if (!match_id.empty()) item->match_id = match_id;
            if (!member_id.empty()) item->member_id = member_id;
            if (!sport.empty()) item->sport = sport;
            item->primary = prompt_int("Primary statistic: ");
            item->secondary = prompt_int("Secondary statistic: ");
            item->tertiary = prompt_int("Tertiary statistic: ");
            std::string error;
            std::cout << (service.update_performance(*item, error) ? "Performance updated.\n" : "Unable to update performance: " + error + "\n");
            continue;
        }
        if (choice == "4") {
            const auto id = prompt("Performance ID to delete: ");
            std::string error;
            std::cout << (service.remove_performance(id, error) ? "Performance deleted.\n" : "Unable to delete performance: " + error + "\n");
            continue;
        }
        if (choice == "5") {
            for (const auto& sport : {std::string("soccer"), std::string("netball"), std::string("track")}) { auto mvp=service.mvp_for_sport(sport); std::cout << sport << ": "; if(mvp) std::cout << mvp->member.first_name << ' ' << mvp->member.last_name << " (score " << mvp->score << ")\n"; else std::cout << "No qualifying statistics.\n"; } continue;
        }
        if (choice == "6") { std::string error; std::cout << (service.write_mvp_file("mvp.txt", error) ? "mvp.txt written.\n" : "Unable to write file: " + error + "\n"); continue; }
        std::cout << "Unknown selection.\n";
    }
}

void data_menu(sms::DataManagementService& data) {
    while (true) {
        std::cout << "\nData Management\n1. Create backup\n2. Restore backup\n3. Verify backup\n0. Back\n";
        const auto choice = prompt("Selection: ");
        if (choice == "0") return;
        const auto path = prompt("Backup directory: ");
        std::string error;
        if (choice == "1") std::cout << (data.create_backup(path,error) ? "Backup created.\n" : "Backup failed: "+error+"\n");
        else if (choice == "2") std::cout << (data.restore_backup(path,error) ? "Backup restored. Restart the application to reload data.\n" : "Restore failed: "+error+"\n");
        else if (choice == "3") { auto entries=data.inspect_backup(path,error); if(!error.empty()) std::cout<<"Verification failed: "<<error<<'\n'; else {std::cout<<"Backup verified: "<<entries.size()<<" files.\n"; for(auto&e:entries)std::cout<<e.file_name<<" | "<<e.size<<" bytes | "<<e.checksum<<'\n';}}
        else std::cout << "Unknown selection.\n";
    }
}

}  // namespace

int main(int argc, char* argv[]) {
    const std::filesystem::path data_directory = argc > 1 ? argv[1] : "data";
    sms::CsvMemberRepository members(data_directory / "members.csv");
    sms::CsvTeamRepository teams(data_directory / "teams.csv");
    sms::CsvMatchRepository matches(data_directory / "matches.csv");
    sms::CsvPerformanceRepository performances(data_directory / "statistics.csv");
    sms::SportsService service(members, teams, matches, &performances);
    sms::DataManagementService data_management(data_directory);

    while (true) {
        std::cout << "\nSports Management System\n"
                  << "Data directory: " << data_directory.string() << "\n"
                  << "1. Teams\n2. Members\n3. Matches\n4. Statistics and MVP\n5. Data Management\n0. Exit\n";
        const auto choice = prompt("Selection: ");
        if (choice == "0") break;
        if (choice == "1") teams_menu(service, teams);
        else if (choice == "2") members_menu(service, members);
        else if (choice == "3") matches_menu(service, matches);
        else if (choice == "4") statistics_menu(service, performances);
        else if (choice == "5") data_menu(data_management);
        else std::cout << "Unknown selection.\n";
    }
    std::cout << "Goodbye.\n";
    return 0;
}
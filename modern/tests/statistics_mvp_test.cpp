#include <cassert>
#include <filesystem>
#include <fstream>
#include <string>
#include "sms/csv_performance_repository.hpp"
#include "sms/in_memory_match_repository.hpp"
#include "sms/in_memory_member_repository.hpp"
#include "sms/in_memory_team_repository.hpp"
#include "sms/sports_service.hpp"
int main(){
    sms::InMemoryMemberRepository members; sms::InMemoryTeamRepository teams; sms::InMemoryMatchRepository matches;
    auto dir=std::filesystem::temp_directory_path()/"sms_mvp_test"; std::filesystem::remove_all(dir);
    sms::CsvPerformanceRepository stats(dir/"statistics.csv"); sms::SportsService service(members,teams,matches,&stats); std::string e;
    assert(service.add_team({"S1","Strikers","soccer",{}},e)); assert(service.add_team({"S2","United","soccer",{}},e));
    assert(service.add_member({"M1","Ada","King","2000-01-01","S1"},e)); assert(service.add_member({"M2","Bob","Stone","2000-02-02","S2"},e));
    assert(service.add_match({"G1","soccer","S1","S2","2026-07-15","Field",2,1},e));
    assert(service.add_performance({"P1","G1","M1","soccer",2,1,0},e));
    assert(service.add_performance({"P2","G1","M2","soccer",1,0,4},e));
    auto mvp=service.mvp_for_sport("soccer"); assert(mvp); assert(mvp->member.id=="M1"); assert(mvp->score==13);
    auto file=dir/"mvp.txt"; assert(service.write_mvp_file(file,e)); std::ifstream in(file); std::string text((std::istreambuf_iterator<char>(in)),{}); assert(text.find("Ada King")!=std::string::npos);
    auto member=*members.find("M1"); member.team_code="UNKNOWN"; assert(!service.update_member(member,e));
    auto match=*matches.find("G1"); match.home_score=-1; assert(!service.update_match(match,e));
    std::filesystem::remove_all(dir); return 0;
}

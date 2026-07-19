#include <cassert>
#include <filesystem>
#include <fstream>
#include <string>
#include "sms/in_memory_member_repository.hpp"
#include "sms/in_memory_team_repository.hpp"
#include "sms/in_memory_match_repository.hpp"
#include "sms/sports_service.hpp"
int main(){sms::InMemoryMemberRepository members;sms::InMemoryTeamRepository teams;sms::InMemoryMatchRepository matches;sms::SportsService service(members,teams,matches);std::string e;assert(service.add_team({"T1","Alpha","soccer"},e));assert(service.add_team({"T2","Beta","soccer"},e));assert(service.add_member({"M1","Dane","Wisdom","T1"},e));assert(service.add_match({"G1","soccer","T1","T2","2026-07-15","Main Field",3,1},e));auto found=service.search_members("wis");assert(found.size()==1&&found[0].id=="M1");auto summaries=service.team_summaries("soccer");assert(summaries.size()==2);assert(summaries[0].team.code=="T1");assert(summaries[0].wins==1&&summaries[0].points_for==3);assert(service.audit_data_quality().empty());auto path=std::filesystem::temp_directory_path()/"sms-report.txt";assert(service.write_report_file(path,e));std::ifstream in(path);std::string text((std::istreambuf_iterator<char>(in)),{});assert(text.find("Alpha")!=std::string::npos);std::filesystem::remove(path);}

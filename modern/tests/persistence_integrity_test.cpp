#include <cassert>
#include <fstream>
#include <limits>
#include <sstream>
#include "sms/csv_support.hpp"
#include "sms/csv_member_repository.hpp"
#include "sms/csv_team_repository.hpp"
#include "sms/csv_match_repository.hpp"
#include "sms/csv_performance_repository.hpp"
#include "sms/data_management.hpp"
#include "sms/sports_service.hpp"

std::string bytes(const std::filesystem::path& p) {std::ifstream f(p,std::ios::binary);return {std::istreambuf_iterator<char>(f),{}};}
void put(const std::filesystem::path& p,const std::string& text) {std::ofstream f(p,std::ios::binary);f<<text;}
template<class F> void rejects(F f) {bool rejected=false;try {f();}catch(const std::exception&){rejected=true;}assert(rejected);}
int main() {
    auto root=std::filesystem::temp_directory_path()/"sms_integrity_regression";
    std::filesystem::remove_all(root);std::filesystem::create_directories(root/"data");
    auto dir=root/"data";
    sms::CsvTeamRepository teams(dir/"teams.csv");sms::CsvMemberRepository members(dir/"members.csv");
    sms::CsvMatchRepository matches(dir/"matches.csv");sms::CsvPerformanceRepository stats(dir/"statistics.csv");
    sms::SportsService service(members,teams,matches,&stats);std::string error;
    assert(service.add_team({"A","Alpha, \"quoted\"\nsecond line","soccer",{}},error));
    assert(service.add_team({"B","Beta","soccer",{}},error));
    assert(teams.find("A")->name=="Alpha, \"quoted\"\nsecond line");
    assert(service.add_member({"M","Ada","King","2000-01-01","A"},error));
    assert(service.add_match({"G","soccer","A","B","2026-01-01","Field",2,1},error));
    assert(service.add_performance({"P","G","M","soccer",2,1,0},error));
    auto before=bytes(dir/"members.csv");
    assert(!service.remove_member("M",error)); assert(bytes(dir/"members.csv")==before);
    assert(service.audit_data_quality().empty());
    assert(service.performance_score({"L","G","M","soccer",std::numeric_limits<int>::max(),0,0})==10737418235LL);
    auto team_bytes=bytes(dir/"teams.csv");
    for(const auto& bad:{std::string("code,name,sport\nA,Alpha,soccer\nA,Duplicate,soccer\n"),std::string("code,name,sport\nA,\"unterminated,soccer\n"),std::string("code,name,sport\nA,\"Alpha\"suffix,soccer\n"),std::string("code,name,sport\nA,missing\n")}) {
        put(dir/"teams.csv",bad); rejects([&]{teams.add({"C","Gamma","soccer",{}});});assert(bytes(dir/"teams.csv")==bad);
    }
    put(dir/"teams.csv",team_bytes);
    auto stat_bytes=bytes(dir/"statistics.csv");
    for(const auto& n:{"3junk","999999999999999999999999",""}) {
        auto bad=std::string("P,G,M,soccer,")+n+",1,0\n";put(dir/"statistics.csv",bad);
        rejects([&]{stats.remove("P");});assert(bytes(dir/"statistics.csv")==bad);
    }
    put(dir/"statistics.csv",stat_bytes);
    sms::DataManagementService data(dir);auto backup=root/"backup";
    assert(data.create_backup(backup,error));assert(data.inspect_backup(backup,error).size()==4);
    auto manifest=bytes(backup/"manifest.txt");
    for(const auto& bad:{std::string("sports-management-system-backup-v1\nbad-row\n"),std::string("sports-management-system-backup-v1\n../teams.csv|1|bad\n"),manifest+manifest.substr(manifest.find('\n')+1),std::string("sports-management-system-backup-v1\nteams.csv|not-a-number|bad\n")}) {
        put(backup/"manifest.txt",bad);assert(!data.restore_backup(backup,error));assert(!error.empty());assert(bytes(dir/"teams.csv")==team_bytes);
    }
    auto wrong_size=manifest;auto a=wrong_size.find('|');auto b=wrong_size.find('|',a+1);wrong_size.replace(a+1,b-a-1,"0");
    put(backup/"manifest.txt",wrong_size);assert(data.inspect_backup(backup,error).empty());assert(!error.empty());
    put(backup/"manifest.txt",manifest);
    put(backup/"teams.csv",team_bytes+"tamper");assert(!data.restore_backup(backup,error));assert(bytes(dir/"teams.csv")==team_bytes);
    put(backup/"teams.csv",team_bytes);put(dir/"teams.csv","broken");assert(data.restore_backup(backup,error));assert(bytes(dir/"teams.csv")==team_bytes);
    assert(!data.create_backup(dir,error));
    std::filesystem::remove_all(root);
}

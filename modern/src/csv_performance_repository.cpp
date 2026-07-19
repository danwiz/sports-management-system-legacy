#include "sms/csv_performance_repository.hpp"
#include "sms/csv_support.hpp"
#include <algorithm>
#include <fstream>
namespace sms {
CsvPerformanceRepository::CsvPerformanceRepository(std::filesystem::path p): file_path_(std::move(p)) {}
std::vector<Performance> CsvPerformanceRepository::load() const {
    std::vector<Performance> out; std::ifstream in(file_path_); std::string line;
    while (std::getline(in,line)) { auto f=csv::parse_line(line); if(f.size()!=7) continue;
        try { out.push_back(Performance{f[0],f[1],f[2],f[3],std::stoi(f[4]),std::stoi(f[5]),std::stoi(f[6])}); } catch(...) {}
    }
    std::sort(out.begin(),out.end(),[](auto&a,auto&b){return a.id<b.id;}); return out;
}
bool CsvPerformanceRepository::save(const std::vector<Performance>& values) const {
    std::filesystem::create_directories(file_path_.parent_path()); auto tmp=file_path_; tmp += ".tmp";
    std::ofstream out(tmp,std::ios::trunc); if(!out) return false;
    for(auto& p:values) out<<csv::escape(p.id)<<','<<csv::escape(p.match_id)<<','<<csv::escape(p.member_id)<<','<<csv::escape(p.sport)<<','<<p.primary<<','<<p.secondary<<','<<p.tertiary<<'\n';
    out.close(); if(!out) return false; std::error_code ec; std::filesystem::rename(tmp,file_path_,ec); if(ec){std::filesystem::remove(file_path_,ec); ec.clear(); std::filesystem::rename(tmp,file_path_,ec);} return !ec;
}
bool CsvPerformanceRepository::add(Performance p){auto v=load(); if(std::any_of(v.begin(),v.end(),[&](auto&x){return x.id==p.id;}))return false; v.push_back(std::move(p)); return save(v);}
bool CsvPerformanceRepository::update(const Performance&p){auto v=load(); auto it=std::find_if(v.begin(),v.end(),[&](auto&x){return x.id==p.id;}); if(it==v.end())return false; *it=p; return save(v);}
bool CsvPerformanceRepository::remove(const std::string&id){auto v=load(); auto n=v.size(); std::erase_if(v,[&](auto&x){return x.id==id;}); return v.size()!=n&&save(v);}
std::optional<Performance> CsvPerformanceRepository::find(const std::string&id) const {for(auto&p:load())if(p.id==id)return p; return std::nullopt;}
std::vector<Performance> CsvPerformanceRepository::list() const{return load();}
}

#include "sms/data_management.hpp"
#include <array>
#include <algorithm>
#include <charconv>
#include <set>
#include "sms/csv_support.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>
namespace sms {
namespace {
constexpr std::array<const char*,4> files{"teams.csv","members.csv","matches.csv","statistics.csv"};
std::string checksum(const std::filesystem::path& path){std::ifstream in(path,std::ios::binary);std::uint64_t hash=1469598103934665603ULL;char c;while(in.get(c)){hash^=static_cast<unsigned char>(c);hash*=1099511628211ULL;}std::ostringstream out;out<<std::hex<<std::setw(16)<<std::setfill('0')<<hash;return out.str();}
bool copy_dataset(const std::filesystem::path& from,const std::filesystem::path& to,std::string& error){std::error_code ec;std::filesystem::create_directories(to,ec);if(ec){error="unable to create destination directory";return false;}for(auto name:files){auto source=from/name;if(!std::filesystem::exists(source))continue;auto temp=to/(std::string(name)+".tmp");std::filesystem::copy_file(source,temp,std::filesystem::copy_options::overwrite_existing,ec);if(ec){error="unable to copy "+std::string(name);return false;}if(!csv::replace_file(temp,to/name)){error="unable to finalize "+std::string(name);return false;}}return true;}
}
bool DataManagementService::create_backup(const std::filesystem::path& dir,std::string& error) const {if(std::filesystem::weakly_canonical(dir)==std::filesystem::weakly_canonical(data_directory_)){error="backup destination must differ from live data";return false;}if(std::filesystem::exists(dir)&&!std::filesystem::is_empty(dir)){error="backup destination must be empty";return false;}if(!copy_dataset(data_directory_,dir,error))return false;std::ofstream manifest(dir/"manifest.txt",std::ios::trunc);if(!manifest){error="unable to create manifest";return false;}manifest<<"sports-management-system-backup-v1\n";for(auto name:files){auto path=dir/name;if(std::filesystem::exists(path))manifest<<name<<'|'<<std::filesystem::file_size(path)<<'|'<<checksum(path)<<'\n';}error.clear();return static_cast<bool>(manifest);}
std::vector<BackupEntry> DataManagementService::inspect_backup(const std::filesystem::path& dir,std::string& error) const {
    std::vector<BackupEntry> entries;
    std::set<std::string> seen;
    std::ifstream manifest(dir/"manifest.txt");
    std::string line;
    auto fail=[&](const std::string& message) {error=message; return std::vector<BackupEntry>{};};
    if(!manifest||!std::getline(manifest,line)||line!="sports-management-system-backup-v1")
        return fail("invalid or missing backup manifest");
    while(std::getline(manifest,line)) {
        auto first=line.find('|'), second=line.find('|',first==std::string::npos?0:first+1);
        if(first==std::string::npos||second==std::string::npos||line.find('|',second+1)!=std::string::npos)
            return fail("malformed backup manifest row");
        auto name=line.substr(0,first), size=line.substr(first+1,second-first-1), hash=line.substr(second+1);
        if(std::find(files.begin(),files.end(),name)==files.end()||!seen.insert(name).second)
            return fail("unknown or duplicate backup file");
        std::uintmax_t expected=0;
        auto [end,ec]=std::from_chars(size.data(),size.data()+size.size(),expected);
        if(ec!=std::errc{}||end!=size.data()+size.size()) return fail("invalid backup size");
        auto path=dir/name;
        std::error_code fs_error;
        if(std::filesystem::is_symlink(path)||!std::filesystem::is_regular_file(path,fs_error)||fs_error)
            return fail("missing or unsafe backup file");
        auto actual=std::filesystem::file_size(path,fs_error);
        if(fs_error||actual!=expected||checksum(path)!=hash) return fail("backup verification failed for "+name);
        entries.push_back({name,expected,hash});
    }
    if(manifest.bad()||entries.empty()) return fail("empty or unreadable backup manifest");
    for(auto name:files) if(std::filesystem::exists(dir/name)&&!seen.count(name))
        return fail("unlisted dataset file in backup");
    error.clear();return entries;
}
bool DataManagementService::restore_backup(const std::filesystem::path& dir,std::string& error) const {auto entries=inspect_backup(dir,error);if(!error.empty())return false;if(entries.empty()){error="backup contains no data files";return false;}return copy_dataset(dir,data_directory_,error);}
bool DataManagementService::export_bundle(const std::filesystem::path& dir,std::string& error) const {return create_backup(dir,error);}
}

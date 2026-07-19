#include "sms/data_management.hpp"
#include <array>
#include <fstream>
#include <iomanip>
#include <sstream>
namespace sms {
namespace {
constexpr std::array<const char*,4> files{"teams.csv","members.csv","matches.csv","statistics.csv"};
std::string checksum(const std::filesystem::path& path){std::ifstream in(path,std::ios::binary);std::uint64_t hash=1469598103934665603ULL;char c;while(in.get(c)){hash^=static_cast<unsigned char>(c);hash*=1099511628211ULL;}std::ostringstream out;out<<std::hex<<std::setw(16)<<std::setfill('0')<<hash;return out.str();}
bool copy_dataset(const std::filesystem::path& from,const std::filesystem::path& to,std::string& error){std::error_code ec;std::filesystem::create_directories(to,ec);if(ec){error="unable to create destination directory";return false;}for(auto name:files){auto source=from/name;if(!std::filesystem::exists(source))continue;auto temp=to/(std::string(name)+".tmp");std::filesystem::copy_file(source,temp,std::filesystem::copy_options::overwrite_existing,ec);if(ec){error="unable to copy "+std::string(name);return false;}std::filesystem::rename(temp,to/name,ec);if(ec){std::filesystem::remove(to/name,ec);ec.clear();std::filesystem::rename(temp,to/name,ec);}if(ec){error="unable to finalize "+std::string(name);return false;}}return true;}
}
bool DataManagementService::create_backup(const std::filesystem::path& dir,std::string& error) const {if(!copy_dataset(data_directory_,dir,error))return false;std::ofstream manifest(dir/"manifest.txt",std::ios::trunc);if(!manifest){error="unable to create manifest";return false;}manifest<<"sports-management-system-backup-v1\n";for(auto name:files){auto path=dir/name;if(std::filesystem::exists(path))manifest<<name<<'|'<<std::filesystem::file_size(path)<<'|'<<checksum(path)<<'\n';}error.clear();return static_cast<bool>(manifest);}
std::vector<BackupEntry> DataManagementService::inspect_backup(const std::filesystem::path& dir,std::string& error) const {std::vector<BackupEntry> entries;std::ifstream manifest(dir/"manifest.txt");std::string line;if(!manifest||!std::getline(manifest,line)||line!="sports-management-system-backup-v1"){error="invalid or missing backup manifest";return entries;}while(std::getline(manifest,line)){std::istringstream in(line);std::string name,size,hash;if(!std::getline(in,name,'|')||!std::getline(in,size,'|')||!std::getline(in,hash))continue;auto path=dir/name;if(!std::filesystem::exists(path)||checksum(path)!=hash){error="backup verification failed for "+name;entries.clear();return entries;}entries.push_back({name,static_cast<std::uintmax_t>(std::stoull(size)),hash});}error.clear();return entries;}
bool DataManagementService::restore_backup(const std::filesystem::path& dir,std::string& error) const {auto entries=inspect_backup(dir,error);if(!error.empty())return false;if(entries.empty()){error="backup contains no data files";return false;}return copy_dataset(dir,data_directory_,error);}
bool DataManagementService::export_bundle(const std::filesystem::path& dir,std::string& error) const {return create_backup(dir,error);}
}

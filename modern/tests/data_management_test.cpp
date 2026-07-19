#include "sms/data_management.hpp"
#include <cassert>
#include <filesystem>
#include <fstream>
#include <string>
int main(){auto root=std::filesystem::temp_directory_path()/"sms_data_management_test";std::filesystem::remove_all(root);auto data=root/"data",backup=root/"backup";std::filesystem::create_directories(data);std::ofstream(data/"teams.csv")<<"T1,Tigers,soccer\n";std::ofstream(data/"members.csv")<<"M1,Ada,Lovelace,1815-12-10,T1\n";sms::DataManagementService service(data);std::string error;assert(service.create_backup(backup,error));auto entries=service.inspect_backup(backup,error);assert(error.empty());assert(entries.size()==2);std::ofstream(data/"teams.csv",std::ios::trunc)<<"BROKEN\n";assert(service.restore_backup(backup,error));std::ifstream restored(data/"teams.csv");std::string value;std::getline(restored,value);assert(value=="T1,Tigers,soccer");std::ofstream(backup/"teams.csv",std::ios::app)<<"tamper";entries=service.inspect_backup(backup,error);assert(entries.empty());assert(!error.empty());std::filesystem::remove_all(root);}

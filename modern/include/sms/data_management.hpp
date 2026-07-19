#pragma once
#include <filesystem>
#include <string>
#include <vector>
namespace sms {
struct BackupEntry { std::string file_name; std::uintmax_t size; std::string checksum; };
class DataManagementService {
public:
    explicit DataManagementService(std::filesystem::path data_directory) : data_directory_(std::move(data_directory)) {}
    bool create_backup(const std::filesystem::path& backup_directory, std::string& error) const;
    bool restore_backup(const std::filesystem::path& backup_directory, std::string& error) const;
    bool export_bundle(const std::filesystem::path& export_directory, std::string& error) const;
    std::vector<BackupEntry> inspect_backup(const std::filesystem::path& backup_directory, std::string& error) const;
private:
    std::filesystem::path data_directory_;
};
}

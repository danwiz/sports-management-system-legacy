#pragma once
#include <filesystem>
#include "sms/performance_repository.hpp"
namespace sms {
class CsvPerformanceRepository final : public PerformanceRepository {
public:
    explicit CsvPerformanceRepository(std::filesystem::path file_path);
    bool add(Performance performance) override;
    bool update(const Performance& performance) override;
    bool remove(const std::string& id) override;
    std::optional<Performance> find(const std::string& id) const override;
    std::vector<Performance> list() const override;
private:
    std::filesystem::path file_path_;
    std::vector<Performance> load() const;
    bool save(const std::vector<Performance>& values) const;
};
}

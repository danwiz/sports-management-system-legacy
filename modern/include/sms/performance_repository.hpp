#pragma once
#include <optional>
#include <string>
#include <vector>
#include "sms/performance.hpp"
namespace sms {
class PerformanceRepository {
public:
    virtual ~PerformanceRepository() = default;
    virtual bool add(Performance performance) = 0;
    virtual bool update(const Performance& performance) = 0;
    virtual bool remove(const std::string& id) = 0;
    virtual std::optional<Performance> find(const std::string& id) const = 0;
    virtual std::vector<Performance> list() const = 0;
};
}

#pragma once

#include <filesystem>
#include "sms/repository.hpp"

namespace sms {

class CsvMemberRepository final : public MemberRepository {
public:
    explicit CsvMemberRepository(std::filesystem::path file_path);

    bool add(Member member) override;
    bool update(const Member& member) override;
    bool remove(const std::string& id) override;
    std::optional<Member> find(const std::string& id) const override;
    std::vector<Member> list() const override;

private:
    std::filesystem::path file_path_;

    std::vector<Member> load() const;
    bool save(const std::vector<Member>& members) const;
};

}  // namespace sms

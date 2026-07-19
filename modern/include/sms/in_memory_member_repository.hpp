#pragma once

#include <unordered_map>
#include "sms/repository.hpp"

namespace sms {

class InMemoryMemberRepository final : public MemberRepository {
public:
    bool add(Member member) override;
    bool update(const Member& member) override;
    bool remove(const std::string& id) override;
    std::optional<Member> find(const std::string& id) const override;
    std::vector<Member> list() const override;

private:
    std::unordered_map<std::string, Member> members_;
};

}  // namespace sms

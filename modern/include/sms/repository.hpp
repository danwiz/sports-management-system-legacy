#pragma once

#include <optional>
#include <string>
#include <vector>
#include "sms/member.hpp"

namespace sms {

class MemberRepository {
public:
    virtual ~MemberRepository() = default;
    virtual bool add(Member member) = 0;
    virtual bool update(const Member& member) = 0;
    virtual bool remove(const std::string& id) = 0;
    virtual std::optional<Member> find(const std::string& id) const = 0;
    virtual std::vector<Member> list() const = 0;
};

}  // namespace sms

#include "sms/in_memory_member_repository.hpp"

#include <utility>

namespace sms {

bool InMemoryMemberRepository::add(Member member) {
    if (member.id.empty() || members_.contains(member.id)) {
        return false;
    }
    members_.emplace(member.id, std::move(member));
    return true;
}

bool InMemoryMemberRepository::update(const Member& member) {
    const auto it = members_.find(member.id);
    if (it == members_.end()) {
        return false;
    }
    it->second = member;
    return true;
}

bool InMemoryMemberRepository::remove(const std::string& id) {
    return members_.erase(id) == 1;
}

std::optional<Member> InMemoryMemberRepository::find(const std::string& id) const {
    const auto it = members_.find(id);
    if (it == members_.end()) {
        return std::nullopt;
    }
    return it->second;
}

std::vector<Member> InMemoryMemberRepository::list() const {
    std::vector<Member> result;
    result.reserve(members_.size());
    for (const auto& [id, member] : members_) {
        (void)id;
        result.push_back(member);
    }
    return result;
}

}  // namespace sms

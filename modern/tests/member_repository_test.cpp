#include <cassert>
#include "sms/in_memory_member_repository.hpp"

int main() {
    sms::InMemoryMemberRepository repository;
    assert(repository.add({"P001", "A", "Player", "2000-01-01", "T1"}));
    assert(!repository.add({"P001", "Duplicate", "Player", "2000-01-01", "T1"}));

    auto member = repository.find("P001");
    assert(member.has_value());
    member->first_name = "Updated";
    assert(repository.update(*member));
    assert(repository.find("P001")->first_name == "Updated");

    assert(repository.remove("P001"));
    assert(!repository.find("P001").has_value());
    return 0;
}

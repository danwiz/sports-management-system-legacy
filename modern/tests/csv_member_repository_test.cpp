#include <cassert>
#include <filesystem>
#include "sms/csv_member_repository.hpp"

int main() {
    const auto path = std::filesystem::temp_directory_path() / "sms_csv_member_repository_test.csv";
    std::error_code error;
    std::filesystem::remove(path, error);

    {
        sms::CsvMemberRepository repository(path);
        assert(repository.add({"P001", "A, B", "Player", "2000-01-01", "T1"}));
        assert(!repository.add({"P001", "Duplicate", "Player", "2000-01-01", "T1"}));
        assert(repository.add({"P002", "Quote \"Name\"", "Runner", "2001-02-03", "T2"}));

        auto member = repository.find("P001");
        assert(member.has_value());
        assert(member->first_name == "A, B");
        member->team_code = "T3";
        assert(repository.update(*member));
        assert(repository.remove("P002"));
    }

    {
        sms::CsvMemberRepository reloaded(path);
        const auto members = reloaded.list();
        assert(members.size() == 1);
        assert(members.front().id == "P001");
        assert(members.front().team_code == "T3");
    }

    std::filesystem::remove(path, error);
    return 0;
}

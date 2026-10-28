#include "sms/csv_member_repository.hpp"
#include "sms/csv_support.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>

namespace sms {
CsvMemberRepository::CsvMemberRepository(std::filesystem::path file_path)
    : file_path_(std::move(file_path)) {}

bool CsvMemberRepository::add(Member member) {
    if (member.id.empty()) {
        return false;
    }
    auto members = load();
    if (std::ranges::any_of(members, [&](const Member& item) { return item.id == member.id; })) {
        return false;
    }
    members.push_back(std::move(member));
    return save(members);
}

bool CsvMemberRepository::update(const Member& member) {
    auto members = load();
    const auto it = std::ranges::find_if(members, [&](const Member& item) { return item.id == member.id; });
    if (it == members.end()) {
        return false;
    }
    *it = member;
    return save(members);
}

bool CsvMemberRepository::remove(const std::string& id) {
    auto members = load();
    const auto original_size = members.size();
    std::erase_if(members, [&](const Member& item) { return item.id == id; });
    return members.size() != original_size && save(members);
}

std::optional<Member> CsvMemberRepository::find(const std::string& id) const {
    const auto members = load();
    const auto it = std::ranges::find_if(members, [&](const Member& item) { return item.id == id; });
    if (it == members.end()) {
        return std::nullopt;
    }
    return *it;
}

std::vector<Member> CsvMemberRepository::list() const {
    return load();
}

std::vector<Member> CsvMemberRepository::load() const {
    std::vector<Member> values;
    for(const auto& f:csv::read_rows(file_path_,5,"id,first_name,last_name,date_of_birth,team_code")) values.push_back({f[0],f[1],f[2],f[3],f[4]});
    return values;
}

bool CsvMemberRepository::save(const std::vector<Member>& members) const {
    std::error_code error;
    if (file_path_.has_parent_path()) {
        std::filesystem::create_directories(file_path_.parent_path(), error);
        if (error) {
            return false;
        }
    }

    const auto temporary = file_path_.string() + ".tmp";
    std::ofstream output(temporary, std::ios::trunc);
    if (!output) {
        return false;
    }
    output << "id,first_name,last_name,date_of_birth,team_code\n";
    for (const auto& member : members) {
        output << csv::escape(member.id) << ','
               << csv::escape(member.first_name) << ','
               << csv::escape(member.last_name) << ','
               << csv::escape(member.date_of_birth) << ','
               << csv::escape(member.team_code) << '\n';
    }
    output.close();
    if (!output) {
        std::filesystem::remove(temporary, error);
        return false;
    }

    return csv::replace_file(temporary, file_path_);
}

}  // namespace sms

cmake_minimum_required(VERSION 3.20)
project(sports_management_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sms_core
    src/csv_support.cpp
    src/in_memory_member_repository.cpp
    src/csv_member_repository.cpp
    src/in_memory_team_repository.cpp
    src/csv_team_repository.cpp
    src/in_memory_match_repository.cpp
    src/csv_match_repository.cpp
    src/csv_performance_repository.cpp
    src/sports_service.cpp
    src/data_management.cpp
)
target_include_directories(sms_core PUBLIC include)

add_executable(sms_app src/main.cpp)
target_link_libraries(sms_app PRIVATE sms_core)

enable_testing()
add_executable(member_repository_test tests/member_repository_test.cpp)
target_link_libraries(member_repository_test PRIVATE sms_core)
add_test(NAME member_repository_test COMMAND member_repository_test)

add_executable(csv_member_repository_test tests/csv_member_repository_test.cpp)
target_link_libraries(csv_member_repository_test PRIVATE sms_core)
add_test(NAME csv_member_repository_test COMMAND csv_member_repository_test)

add_executable(sports_service_test tests/sports_service_test.cpp)
target_link_libraries(sports_service_test PRIVATE sms_core)
add_test(NAME sports_service_test COMMAND sports_service_test)

add_executable(csv_team_match_repository_test tests/csv_team_match_repository_test.cpp)
target_link_libraries(csv_team_match_repository_test PRIVATE sms_core)
add_test(NAME csv_team_match_repository_test COMMAND csv_team_match_repository_test)

add_executable(statistics_mvp_test tests/statistics_mvp_test.cpp)
target_link_libraries(statistics_mvp_test PRIVATE sms_core)
add_test(NAME statistics_mvp_test COMMAND statistics_mvp_test)

add_executable(reporting_test tests/reporting_test.cpp)
target_link_libraries(reporting_test PRIVATE sms_core)
add_test(NAME reporting_test COMMAND reporting_test)

add_executable(data_management_test tests/data_management_test.cpp)
target_link_libraries(data_management_test PRIVATE sms_core)
add_test(NAME data_management_test COMMAND data_management_test)

include(GNUInstallDirs)
install(TARGETS sms_app RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY sample-data/ DESTINATION ${CMAKE_INSTALL_DATADIR}/sports-management-system/sample-data)
install(FILES ../README.md ../RELEASE_NOTES.md DESTINATION ${CMAKE_INSTALL_DOCDIR})

set(CPACK_PACKAGE_NAME "sports-management-system")
set(CPACK_PACKAGE_VENDOR "Dane Wisdom")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Modern C++20 restoration of a legacy sports management system")
set(CPACK_PACKAGE_VERSION "0.10.0")
set(CPACK_GENERATOR "TGZ;ZIP")
include(CPack)

# Requirements Traceability Matrix

This matrix maps the recovered 2005–2006 assignment specification and user-acceptance feedback to the preserved artifacts, portable C++20 implementation, automated evidence, and active modernization backlog.

## Status definitions

- **Implemented** — present in the modern implementation with direct validation evidence.
- **Partial** — materially supported, but some original fields, interaction details, or evidence remain incomplete.
- **Deferred** — intentionally assigned to a later modernization increment.
- **Archival-only** — preserved as historical evidence and not reproduced as a current feature.
- **Not applicable** — obsolete presentation behavior or platform-specific implementation detail intentionally not carried forward.

## Assignment requirements

| ID | Source requirement | Expected behavior | Modern implementation | Evidence | Status | Follow-up |
|---|---|---|---|---|---|---|
| ASG-01 | Develop the system in C++ | A C++ sports-management application | `modern/` uses portable C++20 and CMake | `.github/workflows/cmake.yml`; all registered CTest suites | Implemented | — |
| ASG-02 | Support soccer, netball, and track and field | Store and process all three sports | `Team::sport`, `Match::sport`, sport-aware performances and MVP scoring | `sports_service_test.cpp`; `statistics_mvp_test.cpp` | Implemented | — |
| ASG-03 | Add, delete, edit, and view teams | Complete team lifecycle | Team repository plus `SportsService::{add,update,remove}_team`; CLI list/add/edit/delete | `sports_service_test.cpp`; CMake CI | Implemented | Issue #11 completed in code |
| ASG-04 | Add, delete, edit, and view matches | Complete match lifecycle | Match repository plus service-routed add/update/remove; full CLI edit workflow | `sports_service_test.cpp`; `csv_team_match_repository_test.cpp` | Implemented | Issue #11 completed in code |
| ASG-05 | Manage team members | Add, edit, delete, view members and associate team code | Member repositories, service validation, CLI lifecycle workflows | `member_repository_test.cpp`; `csv_member_repository_test.cpp`; `sports_service_test.cpp` | Implemented | Issue #10 completed in code |
| ASG-06 | Persist all entered data using files | Data survives application restarts | CSV repositories for teams, members, matches, and performances | CSV repository tests; sample data; backup tests | Implemented | — |
| ASG-07 | Write MVP names to `mvp.txt` | Generate a separate MVP file | `SportsService::write_mvp_file` | `statistics_mvp_test.cpp` | Implemented | — |
| ASG-08 | Display team statistics | Played, wins, losses, draws and scoring totals | `SportsService::team_summaries` and operational report | `reporting_test.cpp` | Implemented | — |
| ASG-09 | Print or report match/system information | Produce usable output covering stored records | Operational text report and CPack/demo outputs | `reporting_test.cpp`; `scripts/demo.sh` | Partial | Rich print/export formats deferred beyond v0.11.0 |
| ASG-10 | Track team code, title, size, squad, coach, captain, wins/losses | Preserve common team attributes | Modern `Team` currently stores code, name, sport, and member identifiers; summary statistics are derived | Team repository and reporting tests | Partial | Future domain-expansion issue required |
| ASG-11 | Track soccer-specific team totals | Cards, reserves, goals for/against | Goals for/against are derivable from matches; card and reserve totals are not modeled | `team_summaries`; reporting | Partial | Future domain-expansion issue required |
| ASG-12 | Track netball-specific team totals | Points for/against | Derived from match scores in team summaries | `reporting_test.cpp` | Implemented | — |
| ASG-13 | Track track-and-field medals and appearances | Gold/silver/bronze, totals, appearances, best time | Performance model supports placing counts; best time and appearance detail are not modeled | `statistics_mvp_test.cpp` | Partial | Future domain-expansion issue required |
| ASG-14 | Track match officials, location, time/date, teams, results, MVP, winner/loser | Complete match record and outcome | Modern `Match` stores teams, schedule, venue, scores and sport; outcomes are derived; officials and per-match MVP are absent | Match repository/service tests | Partial | Future domain-expansion issue required |
| ASG-15 | Track sport-specific match details | Soccer penalties/corners/throws, netball penalties/free passes, track false starts | Not represented in current portable domain | None | Deferred | Future sport-event-detail issue required |
| ASG-16 | Track member name, address, DOB, ID, faculty | Store member identity and affiliation | ID, first/last name, DOB and team are modeled; address/faculty are absent | Member repository tests | Partial | Future member-profile expansion issue required |
| ASG-17 | Identify players participating in multiple sports | Cross-sport participation analysis | Current member has one team code and does not model multi-sport memberships | None | Deferred | Future many-to-many membership issue required |
| ASG-18 | Factor redundancies using OO design | Separate domain, service, and repository responsibilities | Domain models, repository interfaces and application service | `ADR-0001-preserve-and-modernize.md`; source layout | Implemented | Issue #13 adds diagrams |
| ASG-19 | Provide noun/verb, class, and relationship analysis | Document object-oriented analysis | Historical assignment is preserved; modern ADR and documentation exist; formal traceability now exists | This matrix; architecture ADR | Partial | Issue #13 adds Mermaid class/component diagrams |
| ASG-20 | Use graphics to improve look and feel | Usable presentation layer | Borland graphics intentionally replaced with portable line-oriented CLI | `main.cpp`; CLI UAT mapping | Not applicable | A future TUI may be considered separately |
| ASG-21 | Comment the code | Explain non-obvious implementation decisions | Modern code uses descriptive types and focused documentation; dense legacy code is preserved unchanged | Repository docs and source review | Partial | Improve inline API documentation incrementally |
| ASG-22 | Hand in IDE, headers, sources, executable and data files | Preserve full historical submission | Available artifacts are archived; several original headers/project files remain missing | `legacy-source/`; `docs/original/`; technical assessment | Archival-only | Continue artifact recovery search |

## UAT findings

| ID | Source defect | Expected behavior | Modern response | Evidence | Status | Follow-up |
|---|---|---|---|---|---|---|
| UAT-01 | Wrong input type freezes or skips fields | Invalid input must not corrupt the input stream | Complete-line input and validated integer parsing with re-prompting | `main.cpp`; CLI mapping | Implemented | — |
| UAT-02 | Inconsistent terminology: data/information, player/member | Use consistent domain vocabulary | Menus and messages consistently use team, member, match, performance, and information | `main.cpp` | Implemented | — |
| UAT-03 | Screen heading does not match operation | Correct contextual headings and messages | Separate labeled menus and operation-specific success/failure messages | `main.cpp` | Implemented | — |
| UAT-04 | No Back/Main option | Every workflow must return without restarting | Each submenu has `0. Back`; root has `0. Exit` | `main.cpp`; CLI mapping | Implemented | — |
| UAT-05 | Sport-inappropriate prompts | Prompts must match the selected sport | Sport-specific performance labels for soccer, netball, and track | `main.cpp` | Implemented | — |
| UAT-06 | Keyboard menu selection fails | Keyboard input must be reliable | Line-based menu selection; unknown choices remain in menu | `main.cpp` | Implemented | — |
| UAT-07 | User should be able to print records | Generate printable/exportable records | Operational text reports, MVP file and release/demo outputs | `reporting_test.cpp`; `write_mvp_file` | Partial | Richer export/print formats deferred |
| UAT-08 | Officials and time examples/prompts are unclear | Clear free-text entry and display | Modern schedule/venue fields accept full text; officials are not modeled | `main.cpp`; `Match` | Partial | Match-domain expansion required |
| UAT-09 | Editing requires retyping unchanged values | Retain existing values when blank | Member, team and full match edits display current values and retain blanks | `main.cpp` | Implemented | — |
| UAT-10 | MVP filename is incorrect | Use `mvp.txt` exactly | Assignment-compatible `mvp.txt` generation | `statistics_mvp_test.cpp` | Implemented | — |
| UAT-11 | Match input overwrites screen graphics | Inputs must not corrupt presentation | Portable CLI has no absolute-coordinate screen drawing | `main.cpp` | Not applicable | — |
| UAT-12 | Prompts appear behind windows/taskbar | All prompts should be visible in one interface | Single terminal process with sequential prompts | `main.cpp` | Not applicable | — |
| UAT-13 | Edit match routes into Add flow | Existing match must update through a distinct path | Full match edit finds the existing record and calls `update_match` | `main.cpp`; `sports_service_test.cpp` | Implemented | — |
| UAT-14 | Member Main Menu option redisplays same submenu | Navigation must return to parent | Explicit Back return from members menu | `main.cpp` | Implemented | — |
| UAT-15 | Cannot correct already-entered member input | Allow editing after creation | Member edit workflow with validation and retained values | `main.cpp`; service tests | Implemented | — |
| UAT-16 | Delete member does not accept an ID | Prompt for member identifier and delete safely | CLI prompts for ID and calls `SportsService::remove_member` | `main.cpp`; `sports_service_test.cpp` | Implemented | — |
| UAT-17 | Member browsing only moves forward and exits unexpectedly | Predictable record review | Deterministic complete list returned to the same menu | `main.cpp`; CLI mapping | Implemented | — |
| UAT-18 | Delete confirmation says team instead of player | Correct entity-specific messages | Member deletion messages identify the member operation | `main.cpp` | Implemented | — |
| UAT-19 | Member display text overlaps DOB | Clean, structured output | One-record-per-line portable output without coordinate overlap | `main.cpp` | Implemented | — |
| UAT-20 | Member record lacks team code | Store and edit team assignment | `Member::team_code` with existence validation | Member/service tests | Implemented | — |

## Modernization and governance requirements

| ID | Requirement | Implementation | Evidence | Status | Follow-up |
|---|---|---|---|---|---|
| MOD-01 | Preserve legacy source separately from modern code | `legacy-source/` and `modern/` are isolated | Provenance and publication manifest | Implemented | — |
| MOD-02 | Enforce referential integrity through the service layer | All CLI mutations use `SportsService`; member/match deletion is blocked by performances | `sports_service_test.cpp`; Increment 1 record | Implemented | Issue #10 |
| MOD-03 | Audit broken references and inconsistent sports | `audit_data_quality` | `reporting_test.cpp` | Implemented | — |
| MOD-04 | Protect operational data | Checksum-verified backup, inspect and restore | `data_management_test.cpp` | Implemented | — |
| MOD-05 | Reproducible build and validation | CMake, CTest and GitHub Actions | Green validation runs | Implemented | — |
| MOD-06 | Reproducible release packaging | Install rules, CPack ZIP/TGZ, demo script | v0.10.0 release; packaging docs | Implemented | — |
| MOD-07 | Visual architecture documentation | Mermaid class, component, sequence and data-flow diagrams | Not yet committed | Deferred | Issue #13 |
| MOD-08 | Portfolio presentation | README badges, release links and Pages-ready case study | `README.md`; `docs/index.md` | Partial | Issue #14 requires repository settings |

## Coverage summary

- **Implemented:** Core CRUD, persistence, statistics, MVP generation, reporting, data audit, backup/restore, safe input, navigation, service-routed mutations, testing, packaging and release governance.
- **Partial:** Rich historical domain fields, print/export breadth, original OO-analysis deliverables, code-comment depth and Pages repository settings.
- **Deferred:** Multi-sport membership, sport-specific event details, expanded member/match/team attributes and Mermaid architecture set.
- **Archival-only:** Missing historical IDE/header/executable artifacts and the original submission package.
- **Not applicable:** Borland-era screen positioning and graphical-window defects intentionally removed by the portable CLI design.

## Maintenance rule

When a requirement changes status, update this matrix in the same pull request or commit as the implementation and test evidence. New deferred work must link to a dedicated GitHub issue.
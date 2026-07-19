# Sports Management System (Legacy C++ Archive)

A preservation and modernization workspace for a University of Technology sports-management coursework project, originally developed in 2005–2006 using Borland-era C++ console graphics.

## Scope

The system manages soccer, netball, and track-and-field teams, matches, players/members, statistics, persistent files, and MVP records. Four related monolithic source revisions are preserved without asserting which one is the final production version.

## Current status

The repository contains two intentionally separate tracks:

- the preserved legacy implementation, which is not build-ready because it depends on missing project headers and obsolete Borland/Windows APIs; and
- a buildable, tested C++20 modernization under `modern/` with persistent storage, interactive workflows, reporting, backup/restore, and release packaging.

## Repository structure

- `legacy-source/` — preserved source revisions
- `docs/original/` — original assignment and acceptance-feedback documents
- `docs/analysis/` — extracted specifications, checksums, and technical assessment
- `mail-discovery/` — evidence log for related-mail searches
- `modern/` — portable C++20 implementation and tests
- `scripts/` — validation and demonstration automation
- `docs/governance/` — provenance and GitHub publication controls

## Principal findings

1. The assignment calls for object-oriented team, match, and member management with file persistence and a separate `mvp.txt` file.
2. The four source revisions are highly similar (roughly 96.7%–99.9% pairwise similarity), indicating iterative fixes rather than independent projects.
3. Each source is about 3,300 lines and references a missing multi-header domain model and persistence layer.
4. User-acceptance feedback identifies navigation, edit/delete workflow, input validation, terminology, display-layout, keyboard, printing, and record-browsing defects.
5. Modernization should preserve the originals and rebuild separately using standard C++20, CMake, tested domain classes, repository interfaces, and a portable CLI/TUI.

## Recommended modernization phases

1. Recover missing headers, data files, IDE/project files, and executable artifacts.
2. Establish the canonical revision using timestamps, functional comparison, and acceptance-test evidence.
3. Extract domain models (`Member`, `Team`, sport-specific teams, `Match`, sport-specific matches).
4. Replace direct file manipulation with repository abstractions and validated serialization.
5. Replace Borland graphics with a portable CLI/TUI presentation layer.
6. Add unit, integration, persistence, and acceptance tests mapped to the original requirements and defect report.

## Provenance

Original project artifacts supplied by Dane Wisdom. Preserve attribution and academic context when redistributing.

## Modernization baseline

The portable C++20 layer now includes both in-memory and CSV-backed member repositories, allowing data to persist across runs without external dependencies. CSV writes use a temporary file and rename step to reduce partial-write risk.

A portable C++20 baseline is available under `modern/`. It intentionally does not modify the archival implementation. It includes domain models, repository abstractions, CSV persistence, a validated application service, a portable CLI, statistics and MVP calculation, reporting, data-quality auditing, backup/restore, automated tests, packaging, and GitHub Actions CI.

Build locally:

```bash
cmake -S modern -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Repository governance

- `CONTRIBUTING.md` defines preservation boundaries and contribution practices.
- `SECURITY.md` identifies supported code and legacy risks.
- `.github/` contains CI, ownership, issue templates, and the pull-request template.
- `docs/architecture/` records architecture decisions.
- `scripts/validate.sh` performs a reproducible configure, build, and test run.

## Current modernization capabilities

- Member CRUD with in-memory and CSV-backed persistence.
- Team CRUD through a repository abstraction.
- Match CRUD through a repository abstraction.
- Application service validation for team assignments, sport consistency, duplicate identifiers, and referentially safe team deletion.
- Reproducible CMake build and three automated regression tests.

## Interactive application

The modern application now provides persistent team, member, and match management through a portable command-line interface.

```bash
cmake -S modern -B build
cmake --build build
./build/sms_app ./data
```

The optional final argument selects the data directory. The application creates and maintains:

- `teams.csv`
- `members.csv`
- `matches.csv`

Every submenu provides an explicit **Back** option. Record editing preserves existing values when blank input is submitted, and invalid numeric score input is rejected without leaving the input stream in a failed state.

## Statistics and MVP

The modern application records per-member performance statistics for a specific match. The three integer fields are interpreted by sport:

- Soccer: goals, assists, saves; score = goals×5 + assists×3 + saves.
- Netball: goals, assists, interceptions; score = goals×2 + assists×3 + interceptions×4.
- Track and field: first-, second-, and third-place results; score = first×10 + second×7 + third×5.

The Statistics and MVP menu can display leaders and create the assignment-compatible `mvp.txt` file.

## Reporting and audit capabilities

The modern service can search member records, calculate team summaries, export an operational text report, and audit stored data for broken references or inconsistent sports. These capabilities are covered by the `reporting_test` regression suite.

## Data protection

The Data Management menu creates checksum-verified backups and safely restores the four-file CSV dataset.

## Release packaging

The modern application now includes install rules, CPack archive generation, sample operational data, and a one-command demonstration workflow:

```bash
./scripts/demo.sh
cmake --install modern/build-demo --prefix modern/stage
cd modern/build-demo && cpack -G ZIP && cpack -G TGZ
```

See `docs/operations/INSTALLATION_AND_PACKAGING.md` and `docs/operations/RELEASE_READINESS_CHECKLIST.md`.

## Licensing

Modern source, automation, and project-authored documentation are available under the MIT License. Preserved files under `legacy-source/` and `docs/original/` remain all-rights-reserved historical artifacts. See `LICENSE.md`.

## GitHub publication

The repository is prepared for `danwiz/sports-management-system-legacy` on branch `main`, with initial annotated tag `v0.10.0`. See `docs/governance/GITHUB_PUBLICATION_MANIFEST.md`.

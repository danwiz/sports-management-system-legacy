# Sports Management System — Legacy C++ Preservation & Modernization

[![CMake](https://github.com/danwiz/sports-management-system-legacy/actions/workflows/cmake.yml/badge.svg)](https://github.com/danwiz/sports-management-system-legacy/actions/workflows/cmake.yml)
[![Release](https://img.shields.io/github/v/release/danwiz/sports-management-system-legacy)](https://github.com/danwiz/sports-management-system-legacy/releases/tag/v0.10.0)
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/modern%20code-MIT-green.svg)](LICENSE.md)

A preservation and modernization case study for a University of Technology sports-management coursework project originally developed in 2005–2006 using Borland-era C++ console graphics.

**Latest release:** [v0.10.0 — Release Packaging and Demonstration Baseline](https://github.com/danwiz/sports-management-system-legacy/releases/tag/v0.10.0)

## Why this project matters

This repository demonstrates how a large, incomplete legacy academic system can be preserved as historical evidence while its behavior is reconstructed as a portable, tested, documented C++20 application.

The project intentionally separates two tracks:

- `legacy-source/` preserves four original monolithic source revisions and their historical context;
- `modern/` provides a buildable C++20 implementation with CMake, persistence, validation, reporting, backup and restore, packaging, and automated tests.

## Verified release state

- Clean GitHub Actions configuration: passed
- C++20 build: passed
- Automated tests: 7 of 7 passed
- Stable release: `v0.10.0`
- Release packaging: ZIP and TGZ through CPack
- Provenance and split-licensing controls: documented

## Modern capabilities

- Team, member, match, and performance lifecycle management
- Service-routed validation and referential-integrity protection
- Full team and match editing with blank-to-retain behavior
- CSV-backed persistent storage
- Soccer, netball, and track-and-field statistics
- Deterministic MVP calculation and `mvp.txt` generation
- Case-insensitive member search
- Team summaries and operational reporting
- Referential-integrity and data-quality auditing
- Checksum-verified backup, restore, and portable export
- Sample data, demonstration scripts, installation rules, and release packaging

## Build and test

```bash
cmake -S modern -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Run the application with an optional data-directory argument:

```bash
./build/sms_app ./data
```

Run the deterministic demonstration and package workflow:

```bash
./scripts/demo.sh
cmake --install modern/build-demo --prefix modern/stage
cd modern/build-demo && cpack -G ZIP && cpack -G TGZ
```

## Repository map

- `legacy-source/` — preserved C++ revisions
- `modern/` — portable implementation, tests, and sample data
- `docs/original/` — original assignment and acceptance-feedback artifacts
- `docs/analysis/` — extracted requirements, checksums, and technical assessment
- `docs/architecture/` — architecture decisions and Mermaid diagrams
- `docs/modernization/` — behavior mappings, traceability, and modernization records
- `docs/operations/` — installation, packaging, and release-readiness guidance
- `docs/governance/` — provenance, publication, and licensing controls
- `scripts/` — validation and demonstration automation

## Architecture and preservation approach

The legacy files remain unchanged and are not treated as current production software. The modernization uses standard C++20, repository abstractions, service-layer validation, CSV persistence, explicit domain types, portable CLI workflows, and regression tests mapped to recovered requirements and UAT evidence.

Architecture views:

- [Architecture diagram index](docs/architecture/README.md)
- [Domain model](docs/architecture/DOMAIN_MODEL.md)
- [Component architecture](docs/architecture/COMPONENT_ARCHITECTURE.md)
- [Validated mutation sequence](docs/architecture/MUTATION_SEQUENCE.md)
- [Backup and restore flow](docs/architecture/BACKUP_RESTORE_FLOW.md)
- [Legacy preservation boundary](docs/architecture/PRESERVATION_BOUNDARY.md)

## Documentation

- [Technical assessment](docs/analysis/TECHNICAL_ASSESSMENT.md)
- [Architecture decision record](docs/architecture/ADR-0001-preserve-and-modernize.md)
- [Requirements traceability matrix](docs/modernization/REQUIREMENTS_TRACEABILITY_MATRIX.md)
- [CLI and UAT mapping](docs/modernization/CLI_UAT_MAPPING.md)
- [Statistics and MVP design](docs/modernization/STATISTICS_AND_MVP.md)
- [Reporting and data quality](docs/modernization/REPORTING_AND_DATA_QUALITY.md)
- [Installation and packaging](docs/operations/INSTALLATION_AND_PACKAGING.md)
- [Release readiness](docs/operations/RELEASE_READINESS_CHECKLIST.md)
- [Provenance and attribution](docs/governance/PROVENANCE_AND_ATTRIBUTION.md)
- [Publication completion record](docs/governance/PUBLICATION_COMPLETE.md)

## Roadmap

The `v0.11.0` work now includes service-routed lifecycle operations, complete team and match editing, sport-specific prompts, formal requirements traceability, and Mermaid architecture documentation. Remaining work is tracked in the repository issues.

## Licensing

Modern source, automation, and project-authored documentation are licensed under MIT. Preserved files under `legacy-source/` and `docs/original/` remain historical, all-rights-reserved artifacts unless explicitly stated otherwise. See [LICENSE.md](LICENSE.md).

## Author

Dane Wisdom — IT Consultant, Solutions Architect, and Founder of Wisdom Technologies.

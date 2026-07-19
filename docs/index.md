---
layout: default
title: Sports Management System Modernization
description: A legacy C++ preservation and C++20 modernization case study by Dane Wisdom.
---

# Sports Management System Modernization

A portfolio case study in legacy preservation, requirements recovery, software modernization, testing, governance, and release engineering.

## Project overview

This project began as a 2005–2006 university sports-management application built with Borland-era C++ console graphics. The original codebase was incomplete, tightly coupled, platform-specific, and dependent on missing headers and historical runtime assumptions.

Rather than overwrite that history, the repository preserves the original artifacts and develops a separate portable C++20 implementation.

## Modernization outcomes

- Portable C++20 architecture with CMake
- Repository abstractions and service-layer validation
- Service-routed lifecycle operations and referential-integrity controls
- Full team and match editing workflows
- CSV-backed persistence
- Team, member, match, and performance workflows
- Sport-specific scoring and deterministic MVP selection
- Search, team summaries, reporting, and data-quality auditing
- Checksum-verified backup, restore, and portable export
- Seven automated regression test suites
- GitHub Actions validation
- CPack ZIP and TGZ distribution generation
- Requirements traceability and Mermaid architecture documentation
- Provenance, licensing, security, and contribution controls

## Engineering decisions

The modernization separates domain logic, persistence, application services, and presentation concerns. Historical source files remain unchanged under `legacy-source/`, while all modern code lives under `modern/`.

The project uses recovered assignment requirements and user-acceptance feedback as traceable evidence for behavior reconstruction.

## Architecture views

- [Architecture diagram index](architecture/README.md)
- [Domain model](architecture/DOMAIN_MODEL.md)
- [Component architecture](architecture/COMPONENT_ARCHITECTURE.md)
- [Validated mutation sequence](architecture/MUTATION_SEQUENCE.md)
- [Backup and restore flow](architecture/BACKUP_RESTORE_FLOW.md)
- [Legacy preservation boundary](architecture/PRESERVATION_BOUNDARY.md)

## Validation

The `v0.10.0` release passed a clean GitHub Actions run:

- Configuration: passed
- Build: passed
- Tests: 7 of 7 passed

## Explore

- [Repository](https://github.com/danwiz/sports-management-system-legacy)
- [Latest release](https://github.com/danwiz/sports-management-system-legacy/releases/tag/v0.10.0)
- [Technical assessment](analysis/TECHNICAL_ASSESSMENT.md)
- [Architecture decision](architecture/ADR-0001-preserve-and-modernize.md)
- [Requirements traceability matrix](modernization/REQUIREMENTS_TRACEABILITY_MATRIX.md)
- [Modernization documentation](modernization/)
- [Operations documentation](operations/)
- [Provenance and attribution](governance/PROVENANCE_AND_ATTRIBUTION.md)

## Next phase

The active `v0.11.0` work has completed lifecycle routing, editing workflows, requirements traceability, and architecture documentation. Remaining maintenance and portfolio work is tracked in the repository issues.

---

Dane Wisdom · IT Consultant · Solutions Architect · Wisdom Technologies

# Migration Backlog

## Phase 0 — Preservation
- Keep every original source and document byte-for-byte.
- Record checksums and provenance.
- Do not silently repair the archival source.

## Phase 1 — Buildable Domain Core
- Model Member, Team, Match, Official, Result, Statistic, and MVP.
- Implement validated identifiers and team-code relationships.
- Add repository interfaces and unit tests.

## Phase 2 — Persistence
- Replace ad-hoc text files with SQLite or JSON repositories.
- Provide importers for legacy files, including `mvp.txt`.
- Add schema versioning and backup/restore.

## Phase 3 — Portable Interface
- Replace Borland console APIs with a portable CLI/TUI.
- Implement consistent menus, keyboard navigation, previous/main-menu actions, and confirmation dialogs.
- Separate presentation text from application logic.

## Phase 4 — Acceptance Criteria
- Convert every UAT defect into an automated or scripted acceptance test.
- Support partial editing without re-entering unchanged fields.
- Add printable/exportable reports.
- Verify terminology and screen headings consistently.

## Phase 5 — Delivery
- Add cross-platform CI, static analysis, sanitizers, packaging, and release notes.
- Publish legacy and modern tracks without conflating them.

## Completed in v0.4.0

- Team and match repository contracts.
- Core referential-integrity validation.
- Regression tests for cross-entity business rules.

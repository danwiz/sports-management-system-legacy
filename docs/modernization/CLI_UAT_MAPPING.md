# CLI Acceptance-Test Mapping

This document maps the portable command-line workflows to defects recorded in the legacy user-acceptance feedback. The full requirement disposition is maintained in `REQUIREMENTS_TRACEABILITY_MATRIX.md`.

| Legacy defect | Modern response | Status |
|---|---|---|
| Wrong input type freezes or skips later input | All input is read as complete lines; integer fields are parsed and re-prompted safely. | Implemented |
| Menus lack Back/Main navigation | Every domain menu has an explicit `0. Back`; the root menu has `0. Exit`. | Implemented |
| Editing requires complete record re-entry | Member, team, match, and performance editing display current values and retain supported values when the user presses Enter. | Implemented |
| Edit match routes into Add flow | Full match editing uses a distinct existing-record update path through `SportsService::update_match`. | Implemented |
| Delete member does not request an ID | Delete explicitly prompts for the member ID and routes through referential-integrity validation. | Implemented |
| Match deletion bypasses related statistics | `SportsService::remove_match` blocks deletion while performance records reference the match. | Implemented |
| Member deletion bypasses related statistics | `SportsService::remove_member` blocks deletion while performance records reference the member. | Implemented |
| Records advance only forward and exit unexpectedly | List operations display deterministic result sets and return to the same menu. | Implemented |
| Prompts or messages appear under incorrect headings | Teams, Members, Matches, and Statistics have separate, consistently labeled menus and operation messages. | Implemented |
| Keyboard menu input behaves unpredictably | Menu selections are line-based; unknown selections remain in the current menu. | Implemented |
| Prompts use generic statistics for every sport | Soccer, netball, and track performance prompts use sport-specific labels. | Implemented |
| Data is lost between sessions | Teams, members, matches, and performances persist to separate CSV files. | Implemented |
| MVP output uses the wrong filename | MVP generation writes the assignment-compatible `mvp.txt`. | Implemented |
| User cannot print or export records | Operational text reports and `mvp.txt` provide portable output; richer print/export formats remain deferred. | Partial |
| Officials and other historical match fields are missing | Schedule, venue, teams, sport, and scores are editable; officials and several sport-event details are not yet modeled. | Partial |

## Current deferred work

The principal remaining gaps are expanded historical domain attributes, multi-sport membership, sport-specific match-event details, richer export formats, and visual architecture documentation. See `REQUIREMENTS_TRACEABILITY_MATRIX.md` and the active `v0.11.0` issues.
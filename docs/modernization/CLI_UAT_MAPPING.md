# CLI Acceptance-Test Mapping

This document maps the modern command-line workflow to defects recorded in the legacy user-acceptance feedback.

| Legacy defect | Modern response |
|---|---|
| Wrong input type freezes or skips later input | All input is read as complete lines; numeric scores are parsed and re-prompted safely. |
| Menus lack Back/Main navigation | Every domain menu has an explicit `0. Back`; the root menu has `0. Exit`. |
| Editing requires complete record re-entry | Member editing displays current values and retains them when the user presses Enter. |
| Edit match routes into Add flow | Match score editing uses a separate update path and requires an existing match ID. |
| Delete member does not request an ID | Delete explicitly prompts for the member ID. |
| Records advance only forward and exit unexpectedly | List operations display complete deterministic result sets and return to the same menu. |
| Prompts or messages appear under incorrect headings | Teams, Members, and Matches have separate, consistently labeled menus. |
| Keyboard menu input behaves unpredictably | Menu selections are line-based and validated; unknown selections remain in the current menu. |
| Data is lost between sessions | Teams, members, and matches are persisted to separate CSV files. |

Remaining modernization work includes service-level validation for all edit operations, richer sport-specific statistics, MVP generation, and import tooling for any surviving legacy data files.

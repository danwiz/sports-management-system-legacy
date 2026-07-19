# Reporting and Data Quality

The v0.8.0 increment adds read-side capabilities without weakening the domain model.

## Team summary fields

- Team identity and sport
- Assigned member count
- Matches played
- Wins, draws, and losses
- Points scored and conceded

## Audit checks

- Members referencing missing teams
- Matches referencing missing teams
- Match sport inconsistent with participating teams
- Negative match scores
- Performances referencing missing members or matches

Reports are written as plain text so they remain portable and can be inspected without proprietary software.

# Statistics and MVP Model

The legacy assignment required sport statistics and MVP names in `mvp.txt`. The modernization introduces a persistent `Performance` record linked to a valid member and match.

## Integrity rules

- The member and match must exist.
- The performance sport must match the match sport.
- The member's team must be one of the participating teams.
- Statistics cannot be negative.
- Performance IDs are unique.

## Scoring

- Soccer: goals × 5 + assists × 3 + saves.
- Netball: goals × 2 + assists × 3 + interceptions × 4.
- Track and field: first places × 10 + second places × 7 + third places × 5.

Ties are resolved deterministically by member ID so repeated runs produce the same result.

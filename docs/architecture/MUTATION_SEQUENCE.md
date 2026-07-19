# Validated Mutation Sequence

This sequence represents add and update operations for teams, members, matches, and performances.

```mermaid
sequenceDiagram
    actor Operator
    participant CLI
    participant Service as SportsService
    participant Repo as Repository interface
    participant CSV as CSV repository
    participant File as CSV file

    Operator->>CLI: Enter record values
    CLI->>Service: add/update(record, error)
    Service->>Service: Validate required fields
    Service->>Repo: Resolve referenced records
    Repo->>CSV: find/list identifiers
    CSV->>File: Read current dataset
    File-->>CSV: Stored rows
    CSV-->>Repo: Records
    Repo-->>Service: Reference results

    alt validation fails
        Service-->>CLI: false + clear error
        CLI-->>Operator: Explain rejection
    else validation succeeds
        Service->>Repo: add/update validated record
        Repo->>CSV: Persist mutation
        CSV->>File: Temporary write + replace
        File-->>CSV: Persistence result
        CSV-->>Repo: success/failure
        Repo-->>Service: result
        Service-->>CLI: success or repository error
        CLI-->>Operator: Confirmation
    end
```

## Interpretation

Validation occurs before persistence. Rejected operations do not mutate stored data. CSV-backed repositories use a temporary-write-and-replace strategy to reduce the risk of partial writes.
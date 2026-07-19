# Component Architecture

This view identifies the runtime boundaries of the portable modernization.

```mermaid
flowchart LR
    User[Operator] --> CLI[Portable CLI\nmodern/src/main.cpp]
    CLI --> Service[SportsService\nvalidation and business rules]
    CLI --> DataService[DataManagementService\nbackup restore verify]

    Service --> MemberRepo[MemberRepository]
    Service --> TeamRepo[TeamRepository]
    Service --> MatchRepo[MatchRepository]
    Service --> PerformanceRepo[PerformanceRepository]

    MemberRepo --> CsvMembers[CsvMemberRepository]
    TeamRepo --> CsvTeams[CsvTeamRepository]
    MatchRepo --> CsvMatches[CsvMatchRepository]
    PerformanceRepo --> CsvPerformances[CsvPerformanceRepository]

    CsvMembers --> MembersFile[(members.csv)]
    CsvTeams --> TeamsFile[(teams.csv)]
    CsvMatches --> MatchesFile[(matches.csv)]
    CsvPerformances --> StatsFile[(statistics.csv)]

    DataService --> MembersFile
    DataService --> TeamsFile
    DataService --> MatchesFile
    DataService --> StatsFile

    Service --> Reports[Reports and mvp.txt]
```

## Interpretation

The CLI is an input/output adapter, not the owner of business rules. Mutations pass through `SportsService`; persistence is hidden behind repository interfaces. `DataManagementService` operates on the complete four-file dataset for checksum-verified backup and restore.
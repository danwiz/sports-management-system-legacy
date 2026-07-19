# Domain Model

This view shows the core modern C++20 domain records and their business relationships. Repository interfaces store the records; `SportsService` enforces cross-record rules.

```mermaid
classDiagram
    class Team {
      +string code
      +string name
      +string sport
    }
    class Member {
      +string id
      +string first_name
      +string last_name
      +string date_of_birth
      +string team_code
    }
    class Match {
      +string id
      +string sport
      +string home_team_code
      +string away_team_code
      +string scheduled_at
      +string venue
      +int home_score
      +int away_score
    }
    class Performance {
      +string id
      +string match_id
      +string member_id
      +string sport
      +int primary
      +int secondary
      +int tertiary
    }
    class TeamSummary {
      +Team team
      +int members
      +int matches_played
      +int wins
      +int draws
      +int losses
      +int points_for
      +int points_against
    }
    class MvpResult {
      +Member member
      +int score
    }

    Team "1" <-- "0..*" Member : assigned by team_code
    Team "1" <-- "0..*" Match : home team
    Team "1" <-- "0..*" Match : away team
    Member "1" <-- "0..*" Performance : member_id
    Match "1" <-- "0..*" Performance : match_id
    TeamSummary --> Team
    MvpResult --> Member
```

## Interpretation

The model deliberately uses identifiers rather than owning object graphs. That keeps CSV serialization simple and makes referential validation explicit in the service layer. A performance is valid only when its member and match exist, its sport matches the match, and the member's team participated in that match.
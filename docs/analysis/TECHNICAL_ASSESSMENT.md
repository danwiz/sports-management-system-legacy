# Technical Assessment

## Architecture observed

The implementation is a large procedural controller that instantiates a domain/persistence layer through headers including `member.h`, `team.h`, sport-specific team classes, sport-specific match-file classes, member-file classes, and `graphix.h`. The source combines presentation, navigation, validation, orchestration, persistence access, and business rules in one compilation unit.

## Compatibility risks

- Pre-standard headers: `iostream.h`, `iomanip.h`, `fstream.h`.
- Platform/compiler dependencies: `conio.h`, `dos.h`, `gotoxy`, `textcolor`, `cprintf`, `getch`, and direct Windows APIs.
- Non-standard entry point: `void main()`.
- Missing dependent headers and project/data files prevent a complete build.
- Character encoding is ISO-8859/CP1252 with box-drawing byte sequences.
- Extensive numeric key-code handling and nested conditionals make navigation fragile.

## Defect themes from acceptance feedback

- Input parsing can freeze or skip fields after type mismatches.
- Add/edit/delete screens and messages are reused incorrectly.
- Menus lack reliable escape/back behavior.
- Keyboard choices and record navigation are inconsistent.
- Edit operations force full re-entry rather than partial updates.
- Delete-player workflow does not collect an ID and uses team terminology.
- Some prompts and field labels refer to the wrong sport or operation.
- Screen coordinates collide, causing overwriting.
- Printing is absent.
- Member records need a team-code relationship.
- MVP output filename must be exactly `mvp.txt`.

## Recommended target architecture

- `domain/`: validated value objects and polymorphic sport entities.
- `application/`: use cases for add, edit, delete, view, statistics, print/export.
- `infrastructure/`: JSON/SQLite repositories and migration importers.
- `presentation/`: portable CLI/TUI with explicit navigation state.
- `tests/`: requirement traceability and regression tests.

Do not rewrite the archive in place. Keep the original revisions immutable and implement modernization on a separate branch or repository area.

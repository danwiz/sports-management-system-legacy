# Contributing

This repository preserves a legacy academic C++ application while developing a separate portable modernization.

## Scope boundaries

- Do not rewrite files under `legacy-source/`; they are archival evidence.
- Place modernization work under `modern/`.
- Document behavior changes against the assignment specification or UAT feedback.
- Add or update tests for every functional change.

## Development workflow

1. Create a focused branch.
2. Configure and build with CMake.
3. Run the test suite with CTest.
4. Keep commits small and descriptive.
5. Open a pull request that explains the legacy behavior, proposed behavior, and validation performed.

## Build and test

```bash
cmake -S modern -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Coding conventions

- C++20 or later.
- Prefer value semantics and RAII.
- Avoid platform-specific console APIs in domain and persistence layers.
- Keep user-interface, domain, and storage concerns separate.
- Use clear domain terminology: member, player, team, match, official, and sport.

# Release Readiness Checklist

## Source and history
- [ ] Legacy files remain unchanged under `legacy-source/`.
- [ ] Modern changes are committed on `main` with an intentional message.
- [ ] `README.md` and `RELEASE_NOTES.md` describe the current release.

## Build and quality
- [ ] Configure with CMake 3.20 or newer.
- [ ] Build with a C++20 compiler.
- [ ] Run `scripts/validate.sh` and confirm all tests pass.
- [ ] Run `scripts/demo.sh` and confirm sample data is staged.
- [ ] Generate ZIP and TGZ packages with CPack.

## Data and operations
- [ ] Verify sample CSV headers against repository parsers.
- [ ] Create and verify a backup before upgrading an existing installation.
- [ ] Run the data-quality audit after restore or migration.
- [ ] Confirm `mvp.txt` generation in the target data directory.

## GitHub publication
- [ ] Create `danwiz/sports-management-system-legacy`.
- [ ] Push `main` and confirm GitHub Actions passes.
- [ ] Configure repository description, topics, license decision, and social preview.
- [ ] Create release `v0.10.0` and attach CPack artifacts.
- [ ] Convert the migration backlog into GitHub issues and milestones.

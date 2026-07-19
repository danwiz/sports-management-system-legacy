# GitHub Publication Manifest

## Target

- Owner: `danwiz`
- Repository: `sports-management-system-legacy`
- Default branch: `main`
- Visibility recommendation: public
- Initial release tag: `v0.10.0`

## Repository description

Preserved 2005–2006 C++ sports-management coursework plus a portable C++20 modernization with CMake, CSV persistence, tests, CLI workflows, reporting, MVP calculation, backup/restore, and release packaging.

## Suggested topics

`cpp`, `cpp20`, `cmake`, `legacy-code`, `software-modernization`, `oop`,
`sports-management`, `console-application`, `csv`, `software-archaeology`,
`academic-project`, `jamaica`

## Publication sequence

```bash
git remote add origin git@github.com:danwiz/sports-management-system-legacy.git
git push -u origin main
git push origin v0.10.0
```

HTTPS alternative:

```bash
git remote add origin https://github.com/danwiz/sports-management-system-legacy.git
git push -u origin main
git push origin v0.10.0
```

## Release verification

1. Confirm GitHub Actions passes.
2. Confirm the README renders and archive boundaries are clear.
3. Confirm `LICENSE.md` distinguishes modern MIT-licensed work from preserved legacy artifacts.
4. Attach the generated ZIP/TGZ package to the `v0.10.0` GitHub release if desired.
5. Create initial issues from `docs/modernization/ISSUE_SEED.md`.

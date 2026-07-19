# Security Policy

## Supported code

Only the `modern/` implementation is intended for active maintenance. The files in `legacy-source/` are preserved for historical and educational analysis and should not be deployed.

## Reporting a vulnerability

Do not publish sensitive vulnerability details in a public issue. Report the affected component, impact, reproduction steps, and suggested mitigation privately to the repository owner through GitHub's private vulnerability reporting feature when enabled.

## Known legacy risks

The archival program uses obsolete compilers, unsafe input patterns, fixed-size buffers, platform-specific console functions, and ad hoc file persistence. Treat it as untrusted legacy code.

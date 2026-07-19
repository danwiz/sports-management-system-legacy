# ADR-0001: Preserve the legacy source and modernize separately

- Status: Accepted
- Date: 2026-07-15

## Context

The recovered program is incomplete, highly coupled to Borland-era console APIs, and accompanied by assignment and UAT evidence. Editing the original files would destroy provenance and make behavioral comparison harder.

## Decision

Maintain two explicit tracks:

1. `legacy-source/` is immutable archival evidence.
2. `modern/` is a portable C++20 implementation organized into domain, application, persistence, and presentation concerns.

Requirements and defects are traced through documentation and tests rather than by progressively rewriting the archival files.

## Consequences

- Historical authenticity is retained.
- Modern code can adopt safe language and design practices.
- Feature parity must be tracked deliberately.
- Missing original headers and data files remain documented gaps rather than silently reconstructed facts.

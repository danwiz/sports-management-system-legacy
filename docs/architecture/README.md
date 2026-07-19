# Architecture Diagrams

These Mermaid views explain the current C++20 implementation and its relationship to the preserved legacy project.

- [Domain model](DOMAIN_MODEL.md) — core records and relationships
- [Component architecture](COMPONENT_ARCHITECTURE.md) — CLI, service, repositories, CSV storage, and data management
- [Validated mutation sequence](MUTATION_SEQUENCE.md) — add/update validation and persistence flow
- [Backup and restore flow](BACKUP_RESTORE_FLOW.md) — checksum-gated dataset protection
- [Preservation boundary](PRESERVATION_BOUNDARY.md) — separation of historical evidence and modern software
- [ADR-0001](ADR-0001-preserve-and-modernize.md) — decision to preserve the originals and modernize independently

All diagrams use Mermaid syntax and render directly on GitHub.
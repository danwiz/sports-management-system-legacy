# Legacy Preservation and Modernization Boundary

The repository intentionally separates historical evidence from current, buildable software.

```mermaid
flowchart LR
    subgraph Archive[Preserved historical and academic artifacts]
        Legacy[legacy-source/*.cpp\nBorland-era revisions]
        Original[docs/original/*\nassignment and UAT documents]
        Analysis[docs/analysis/*\nextracted text checksums assessment]
    end

    subgraph Evidence[Interpretation and governance]
        Provenance[Provenance and attribution]
        Traceability[Requirements traceability matrix]
        ADR[ADR-0001 preserve and modernize]
    end

    subgraph Modern[Portable C++20 modernization]
        Domain[Domain models]
        Service[SportsService]
        Repositories[Repository interfaces and CSV adapters]
        CLI[Portable CLI]
        Tests[CTest regression suites]
        CI[GitHub Actions and packaging]
    end

    Legacy --> Analysis
    Original --> Analysis
    Analysis --> Traceability
    Provenance --> Archive
    ADR --> Modern
    Traceability --> Modern

    Archive -. no direct build dependency .-> Modern
```

## Interpretation

The modernization does not edit, compile, or silently replace the preserved source revisions. Historical files remain evidence of the original coursework. Requirements and UAT findings are interpreted through analysis, provenance, ADRs, and the traceability matrix before they influence the independent C++20 implementation.
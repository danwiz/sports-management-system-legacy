# Workflow Permission Split

The verified source importer intentionally excludes `.github/workflows/` from its runner-authored commit because the default GitHub Actions token cannot create or update workflow files without the separate workflows permission.

After the source import succeeds, the CMake workflow is added through the connected GitHub integration as a separate authorized commit.

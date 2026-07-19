# Backup, Restore, and Export

The modern application treats `teams.csv`, `members.csv`, `matches.csv`, and `statistics.csv` as one operational dataset.

## Backup

The Data Management menu copies all present dataset files into a selected directory and creates `manifest.txt`. The manifest records each file name, byte size, and deterministic checksum.

## Verification

Before restore, every listed file is checked against its manifest checksum. Missing or modified files cause verification and restore to fail.

## Restore

Restore uses temporary files and replacement semantics. Restart the application after a successful restore so repositories reload the restored files.

## Export

A verified backup directory is also a portable export bundle. It can be transferred between installations while preserving the plain CSV data model.

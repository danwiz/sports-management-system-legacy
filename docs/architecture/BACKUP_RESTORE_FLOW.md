# Backup and Restore Data Flow

This view shows how the modern application protects the complete persistent dataset.

```mermaid
flowchart TD
    DataDir[Active data directory] --> Members[members.csv]
    DataDir --> Teams[teams.csv]
    DataDir --> Matches[matches.csv]
    DataDir --> Stats[statistics.csv]

    Members --> Backup[DataManagementService create_backup]
    Teams --> Backup
    Matches --> Backup
    Stats --> Backup

    Backup --> Copy[Copy files to backup directory]
    Copy --> Hash[Calculate checksums and sizes]
    Hash --> Manifest[(backup manifest)]

    BackupDir[Backup directory] --> Inspect[inspect_backup]
    Manifest --> Inspect
    Inspect --> Verify{All files and checksums valid?}
    Verify -- No --> Reject[Reject restore and report error]
    Verify -- Yes --> Restore[restore_backup]
    Restore --> Stage[Stage verified files]
    Stage --> Replace[Replace active dataset]
    Replace --> Restart[Restart application to reload repositories]
```

## Interpretation

The dataset is treated as one operational unit. Restore is gated by manifest and checksum validation so an incomplete or modified backup is rejected before active files are replaced.
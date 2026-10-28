# Reproducible synthetic demonstration

The maintained checkout contains synthetic people, teams and statistics. No original academic or proprietary data is used. The demonstration runs in a temporary directory, leaving live datasets unchanged.

Requires a C++20 compiler, CMake 3.20 or newer, and Python 3. Configure and run from the repository root:

```sh
cmake -S modern -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug --parallel 2
ctest --test-dir build -C Debug --output-on-failure --timeout 30
python scripts/demo.py --app build/sms_app --output demo-evidence
```

With Visual Studio on Windows, use `--app build/Debug/sms_app.exe`. The evidence destination must be new or empty; the script never deletes existing user files. To install the application, run `cmake --install build --config Debug --prefix stage`.

The script lists four teams, four members, one match and two performance records, selects Alicia Brown as the soccer MVP with score 13, writes `mvp.txt`, creates a backup and verifies four dataset files. It saves the commands, terminal capture, MVP output, backup and a SHA-256 manifest. The [checked-in terminal capture](evidence/DEMO_TERMINAL.txt) is reproducible evidence from the maintained source. CTest runs the same demonstration on all three platforms.

## Version boundary

The corrected sample schema and EOF behavior are changes after v0.11.0. Use the maintained checkout for this demo. The immutable v0.11.0 packages retain the earlier sample-data mismatch and EOF limitation; do not interpret this transcript as evidence for those binaries.

## Integrity behavior and limits

Malformed quoting, wrong field counts, duplicate identifiers and invalid integer fields now fail closed instead of silently discarding rows. Rejected loads cannot overwrite the corrupt source. Recover the source from a verified backup or repair a copy before retrying.

Backup verification rejects malformed rows, duplicate or unexpected names, incorrect sizes, unlisted dataset files and checksum mismatches before copying data. Backups must use a separate empty directory. The legacy backup checksum is a compatibility checksum, not a cryptographic authenticity guarantee; SHA-256 release/evidence manifests serve a different purpose. Restore replaces the verified files; files absent from a partial backup remain in the destination. Multi-file restore is not a transaction and concurrent writers are not supported. File replacement retains a recovery copy on Windows if installation of a replacement fails.

EOF cancels the unfinished form before a service mutation; previously completed operations remain saved. Invalid numeric input is reprompted, integer overflow is rejected, and score calculations use 64-bit arithmetic.

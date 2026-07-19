#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${1:-$ROOT/build}"
cmake -S "$ROOT/modern" -B "$BUILD_DIR"
cmake --build "$BUILD_DIR"
ctest --test-dir "$BUILD_DIR" --output-on-failure

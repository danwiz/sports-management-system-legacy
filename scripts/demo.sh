#!/usr/bin/env bash
set -euo pipefail
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${BUILD_DIR:-$ROOT_DIR/modern/build-demo}"
DATA_DIR="${DATA_DIR:-$ROOT_DIR/modern/demo-data}"
rm -rf "$BUILD_DIR" "$DATA_DIR"
cmake -S "$ROOT_DIR/modern" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$BUILD_DIR" --parallel
ctest --test-dir "$BUILD_DIR" --output-on-failure
mkdir -p "$DATA_DIR"
cp "$ROOT_DIR"/modern/sample-data/*.csv "$DATA_DIR"/
printf 'Demo build and sample data are ready.\nExecutable: %s\nData: %s\n' "$BUILD_DIR/sms_app" "$DATA_DIR"

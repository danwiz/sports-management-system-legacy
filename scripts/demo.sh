#!/usr/bin/env bash
set -euo pipefail
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${BUILD_DIR:-$ROOT_DIR/modern/build-demo}"
cmake -S "$ROOT_DIR/modern" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$BUILD_DIR" --config Debug --parallel 2
ctest --test-dir "$BUILD_DIR" -C Debug --output-on-failure --timeout 30
APP="$BUILD_DIR/sms_app"
if [[ -f "$BUILD_DIR/Debug/sms_app.exe" ]]; then APP="$BUILD_DIR/Debug/sms_app.exe"; fi
python3 "$ROOT_DIR/scripts/demo.py" --app "$APP"

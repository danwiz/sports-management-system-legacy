# Installation and Packaging

## Build

```bash
cmake -S modern -B modern/build -DCMAKE_BUILD_TYPE=Release
cmake --build modern/build --parallel
ctest --test-dir modern/build --output-on-failure
```

## Install to a staging prefix

```bash
cmake --install modern/build --prefix modern/stage
```

The staged tree contains the executable, sample CSV data, README, and release notes.

## Create distributable archives

```bash
cd modern/build
cpack -G ZIP
cpack -G TGZ
```

## Demonstration setup

Run `scripts/demo.sh`. It performs a clean release build, executes the test suite, and copies the sample dataset into `modern/demo-data`.

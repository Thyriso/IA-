# Open CAM Platform

This repository hosts an experimental Computer Aided Manufacturing (CAM) prototype. The goal is to provide a modular, plugin–oriented framework that can generate toolpaths for milling and additive processes.

The project is written in **C++20** and uses **CMake** together with **Conan** to manage third‑party dependencies. A minimal Qt based viewer allows loading and inspecting STL or STEP models.

## Build instructions

```bash
# install dependencies
./scripts/setup_conan.sh

# install packages and configure
conan install . --output-folder=build --build=missing
cmake -S . -B build -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake

# compile
cmake --build build
```

Unit tests can be executed with `ctest --test-dir build` when the `ENABLE_TESTS` option is enabled. To build the optional Qt GUI, pass `-DENABLE_GUI=ON` to CMake (Qt 6 must be installed).

## Packaging

Packages can be generated with CPack once the project is configured:

```bash
cmake --build build --target package
```

## Documentation

Run Doxygen to generate the API reference:

```bash
doxygen Doxyfile
```

The resulting HTML can be published automatically via GitHub Actions.

## Internationalization

Qt translation sources are stored in `translations/`. Run the helper script to update them whenever user‑visible strings change:

```bash
./scripts/update_translations.sh
```

Compiled `.qm` files can then be generated with `lrelease` as part of the build or manually.

#!/usr/bin/env bash
set -euo pipefail

# Install Conan and create default profile
pip install --upgrade conan
conan profile detect --force
sed -i 's/compiler.cppstd=.*/compiler.cppstd=20/' "$HOME/.conan2/profiles/default"

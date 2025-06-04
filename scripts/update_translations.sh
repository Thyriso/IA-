#!/usr/bin/env bash
set -euo pipefail

# Update Qt translation sources (.ts files)
# Requires the `lupdate` tool from Qt to be installed and in PATH.

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="${SCRIPT_DIR}/.."

lupdate "${ROOT_DIR}/src" -ts "${ROOT_DIR}/translations/en.ts" "${ROOT_DIR}/translations/fr.ts"

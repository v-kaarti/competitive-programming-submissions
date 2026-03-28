#!/usr/bin/env bash
set -euo pipefail

WORKSPACE_DIR="$(cd "$(dirname "$0")/.." && pwd)"
CLANGD_FILE="$WORKSPACE_DIR/.clangd"

if [[ -n "${CXX:-}" ]]; then
  compiler="$CXX"
elif command -v g++-14 >/dev/null 2>&1; then
  compiler="g++-14"
else
  compiler="g++"
fi

if ! command -v "$compiler" >/dev/null 2>&1; then
  echo "Compiler not found: $compiler" >&2
  exit 1
fi

cat > "$CLANGD_FILE" <<EOF
CompileFlags:
  Compiler: $compiler
EOF

echo "Wrote $CLANGD_FILE with Compiler: $compiler"
#!/usr/bin/env bash
set -euo pipefail

FILE="$1"
WORKSPACE_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BIN_DIR="$WORKSPACE_DIR/bin"
INPUT_FILE="$WORKSPACE_DIR/input.txt"
OUTPUT_FILE="$WORKSPACE_DIR/output.txt"

mkdir -p "$BIN_DIR"

FILENAME="$(basename "$FILE")"
NAME_NO_EXT="${FILENAME%.*}"
OUT_FILE="$BIN_DIR/$NAME_NO_EXT"

if [[ -n "${CXX:-}" ]]; then
  COMPILER="$CXX"
elif command -v g++-14 >/dev/null 2>&1; then
  COMPILER="g++-14"
else
  COMPILER="g++"
fi

if ! command -v "$COMPILER" >/dev/null 2>&1; then
  echo "Compiler not found: $COMPILER" >&2
  exit 1
fi

"$COMPILER" -std=c++20 "$FILE" -o "$OUT_FILE"
"$OUT_FILE" < "$INPUT_FILE" > "$OUTPUT_FILE"
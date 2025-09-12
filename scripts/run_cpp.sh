#!/usr/bin/env bash
# Helper to compile and run a single C++ file quickly.
set -euo pipefail

# Two calling modes supported:
# 1) Legacy: run_cpp.sh <source.cpp> [-- args...]  (keeps previous behavior)
# 2) Task-friendly: run_cpp.sh <workspaceRoot> <source.cpp> <build|run> [-- args...]

if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <source.cpp> [-- args...]  OR  $0 <workspaceRoot> <source.cpp> <build|run> [-- args...]"
  exit 2
fi

if [ "$#" -ge 3 ] && [ -d "$1" ] && [[ "$3" == "build" || "$3" == "run" ]]; then
  # Task-friendly invocation
  WORKSPACE_ROOT="$1"
  SRC="$2"
  ACTION="$3"
  shift 3
  EXTRA_ARGS=("$@")
else
  # Legacy invocation
  WORKSPACE_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
  SRC="$1"
  shift || true
  ACTION="run"
  EXTRA_ARGS=("$@")
fi

if [ ! -f "$SRC" ]; then
  echo "Source file not found: $SRC"
  exit 3
fi

# Determine output path: mirror workspace-relative directory into out/
SRC_DIR=$(dirname "$SRC")
REL_DIR=$(realpath --relative-to "$WORKSPACE_ROOT" "$SRC_DIR")
OUT_DIR="$WORKSPACE_ROOT/out/$REL_DIR"
BASENAME=$(basename "$SRC" .cpp)
OUT_PATH="$OUT_DIR/$BASENAME"

if [ "$ACTION" = "build" ]; then
  mkdir -p "$OUT_DIR"
  g++ -std=c++17 -O2 -g "$SRC" -o "$OUT_PATH"
  echo "Built $OUT_PATH"
  exit $?
elif [ "$ACTION" = "run" ]; then
  # If binary already exists under out, run it; otherwise build then run
  if [[ -x "$OUT_PATH" ]]; then
    "$OUT_PATH" "${EXTRA_ARGS[@]}" || true
    exit 0
  else
    mkdir -p "$OUT_DIR"
    g++ -std=c++17 -O2 -g "$SRC" -o "$OUT_PATH"
    echo "Built $OUT_PATH"
    "$OUT_PATH" "${EXTRA_ARGS[@]}"
    exit $?
  fi
else
  echo "Unknown ACTION: $ACTION"
  exit 2
fi

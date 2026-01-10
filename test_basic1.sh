#!/usr/bin/env bash
set -euo pipefail
binary="$(mktemp)"
trap 'rm -f "$binary"' EXIT
g++ -std=c++14 -Wall -Wextra -Werror basic1.cpp -o "$binary"
test "$(printf 'output \"hello v2\"\n' | "$binary")" = 'hello v2'
if printf 'invalid\n' | "$binary" >/dev/null 2>&1; then
  echo 'invalid input unexpectedly succeeded' >&2
  exit 1
fi
echo 'LLVM-and-more v2 smoke test passed'

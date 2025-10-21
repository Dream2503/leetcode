#!/bin/bash

set -e

DIR="/mnt/d/achha/Dream/leetcode"
OUT="$DIR/all_in_one.hpp"

rm -f "$OUT"
echo "#pragma once" >> "$OUT"
echo >> "$OUT"

find "$DIR" -type f \( -name "*.h" -o -name "*.hpp" -o -name "*.cpp" \) ! -path "$OUT" | sort | while read -r file; do
    rel="${file#$DIR/}"
    rel="${rel//\\//}"
    echo "#include \"$rel\"" >> "$OUT"
done

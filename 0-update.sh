#!/bin/bash
# Hardcoded merge headers script

set -e

DIR="/mnt/d/achha/Dream/leetcode"
OUT="$DIR/all_in_one.hpp"

# Create/empty the output file and add #pragma once
echo "#pragma once" >> "$OUT"


find "$DIR" -type f \( -name "*.h" -o -name "*.hpp" -o -name "*.cpp" \) ! -path "$OUT" | sort | while read -r file; do
        rel="${file#$DIR/}"
        rel="${rel//\\//}"
        echo "#include \"$rel\"" >> "$OUT"
    done

echo "Includes written to: $OUT"

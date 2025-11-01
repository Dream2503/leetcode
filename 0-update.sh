#!/bin/bash
set -e

DIR="/mnt/d/achha/Dream/leetcode"
OUT="$DIR/all_in_one.hpp"

{
    echo "#pragma once"
    echo

    for f in "$DIR"/*.cpp; do
        [ -f "$f" ] && echo "#include \"${f#$DIR/}\""
    done
} > "$OUT"

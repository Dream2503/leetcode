#!/bin/bash
set -e

DIR="/home/dream/github/leetcode"
OUT="$DIR/all_in_one.hpp"

mapfile -t files < <(
    find "$DIR" -maxdepth 1 -type f -name '*.cpp' -printf '%f\n' |
    awk -F. '$1 ~ /^[0-9]+$/ { print $1 "\t" $0 }' |
    sort -t $'\t' -k1,1n -k2,2 |
    cut -f2-
)

{
    echo "#pragma once"
    echo

    for f in "${files[@]}"; do
        printf '#include "%s"\n' "$f"
    done
} > "$OUT"

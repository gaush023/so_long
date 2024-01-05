#!/bin/bash

filename="$1"

if [ ! -f "$filename" ] || [ ! -r "$filename" ]; then
    echo "ファイルが存在しないか、読み取り不可能です。"
    exit 1
fi

tr '\n' ' ' < "$filename"

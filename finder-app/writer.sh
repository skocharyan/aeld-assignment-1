#!/bin/bash

if [ $# -ne 2 ] || [ -z "$1" ] || [ -z "$2" ]; then 
    echo "Usage: $0 <file_path> <string_to_write>"
    exit 1
fi

DIR_NAME="$(dirname "$1")"

if [ ! -d "$DIR_NAME" ]; then 
    mkdir -p "$DIR_NAME"
    echo "Creating ${DIR_NAME} directory"
fi

cat <<< "$2" > "$1" 

exit 0
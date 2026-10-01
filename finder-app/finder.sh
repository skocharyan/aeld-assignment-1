#!/bin/bash

if [ $# -ne 2 ] || [ ! -d "$1" ] || [ -z "$2" ]
then
    echo "Invalid argument provided"
    exit 1
fi

FILE_COUNT=$(find "$1" -type f | wc -l)
MATCHED_ROW_COUNT=$(find "$1" -type f -exec grep -h "$2" {} + | wc -l)

echo "The number of files are $FILE_COUNT and the number of matching lines are $MATCHED_ROW_COUNT"

exit 0
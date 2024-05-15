#!/bin/bash

FILE="/home/bobadmin/OS-Project_File-System/src/test/test.txt"
ATTR_NAME="user.test"

# Create a test file
touch "$FILE"

# Start with a small size and increase
SIZE=1
STEP=1024

while true; do
    VALUE=$(head -c $SIZE < /dev/zero | tr '\0' 'A')
    setfattr -n "$ATTR_NAME" -v "$VALUE" "$FILE" 2>/dev/null
    if [ $? -ne 0 ]; then
        echo "Maximum attribute size: $((SIZE - STEP)) bytes"
        break
    fi
    SIZE=$((SIZE + STEP))
done

# Clean up
rm -f "$FILE"
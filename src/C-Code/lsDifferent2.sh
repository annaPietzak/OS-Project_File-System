#!/bin/bash

case "$1" in
  "-a")
  	# -a case for showing all the files
    ls -a "$@"
    ;;
  "help")
    # Help case for showing user, how it works
    echo "Usage: $0 <tag_name> or -a"
    echo " List files with the specified tag."
    echo " If no attribute is given, behaves like the normal 'ls' command."
    exit 0
    ;;
  *) 
    # Default case: find files and folders with the extended attribute
    if [ -z "$1" ]; then
    	ls "$@"
    else
    	find . -name "*.*" -exec getfattr -n "user.$1" {} + 2>/dev/null | grep -v "No such attribute"
    fi
    ;;
esac

#!/bin/bash

# This file is responsible for showing you files with different options. ls shows you the files in the
# current directory, ls -a shows you all files in the current directory, help gives you a quick overview,
# how this script works and tag_name shows you all files that have that specific tagName.

# Check if at least one argument is given
if [ $# -eq 0 ]; then
  echo "Usage: $0 {-a|help|ls|tag_name}"
  exit 1
fi

case "$1" in
  "-a")
  	# -a case for showing all the files
    ls -a
    ;;
  "help")
    # Help case for showing user, how it works
    echo "Usage: $0 {-a|help|ls|tag_name}"
    echo " help shows you this (how it works)."
    echo " ls and -a are like the normal ls command. They show you the files of the current directory."
    echo " tag_name lists all the files that have the specified tag."
    exit 0
    ;;
  "ls")
	  ls
   	;;
  *) 
    # Default case: find files and folders with the extended attribute
    find . -exec getfattr -n "user.$1" {} + 2>/dev/null | grep -v "No such attribute"
    ;;
esac

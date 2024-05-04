#!/bin/bash

case "$1" in
  "-a")
	# Case when the user wants to see all the files
  	ls -a "$@"
  	;;
  "help")
  	# Help case in case the user doesn't know, how to use it
	echo "Usage: $0 <tag_name>"
	echo " List files with the specified tag."
	echo " If no attribute is given, behaves like the normal 'ls' command."
	exit 0
    ;;
  *) 
  	# Default case where only files with the extended attribute are shown
	if [ -z "$1" ]; then
		ls "$@"
	else
		getfattr -R -L -n "user.$1" "$@"
	fi
    ;;
esac

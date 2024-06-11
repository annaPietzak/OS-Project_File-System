#!/bin/bash

# This is our main script which calls all the other main files we have (open_help, mkfile, lsDifferent2,
# deleteTag, listAll).

filePath=/home/$USER/.eftas
filePath2=/home/$USER/OS-Project_File-System/src/

# Check if at least one argument is given
if [ $# -eq 0 ]; then
  echo "Usage: $0 {help|mkfile|tagFile|ls|deleteTag|listAll|newTag|showAllTags}"
  exit 1
fi

case "$1" in
  "help")
	  # Help case
  	sh "$filePath/open_help.sh"
    ;;
  "mkfile")
  	# Make a file case
    "$filePath/mkfile_main" $2 $3
    ;;
  "tagFile")
    # Make a file case
    "$filePath/mkfile_main" $2 $3
    ;;
  "ls")
    # Our version of ls case
	  if [ -z "$2" ]; then
	    # When there are no additional arguments, reset positional parameters
	    set --
	    sh "$filePath/lsDifferent2.sh"
	  else
	    sh "$filePath/lsDifferent2.sh" "$2"
	  fi
   	;;
  "deleteTag")
    # Delete tag from file case
	  "$filePath/deleteTag_main" $2 $3
   	;;
  "listAll")
   	# List all tags from specific file case
   	"$filePath/listAll_main" $2
   	;;
  "newTag")
   	# Add a name to the known tags case
   	"$filePath/newTag_main" $2
   	;;
  "showAllTags")
   	# Prints a list of all available tags case
   	"$filePath/showAvailableTags"
   	;;
  *)
    # Default case: show the usage
    echo "Usage: $0 {help|mkfile|tagFile|ls|deleteTag|listAll|newTag|showAllTags}"
    exit 0
    ;;
esac

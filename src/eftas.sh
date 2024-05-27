#!/bin/bash

# This is our main script which calls all the other main files we have (open_help, mkfile, lsDifferent2,
# deleteTag, listAll).

# Check if at least one argument is given
if [ $# -eq 0 ]; then
  echo "Usage: $0 {help|mkfile|lsDifferent2|deleteTag}"
  exit 1
fi

case "$1" in
  "help")
	# Help case
  	source /home/$USER/OS-Project_File-System/src/open_help.sh
    ;;
  "mkfile")
  	# Make a file case
    /home/$USER/OS-Project_File-System/src/mkfile_main $2 $3 $4
    ;;
  "lsDifferent2")
    # Our version of ls case
	  if [ -z "$2" ]; then
	    # When there are no additional arguments, reset positional parameters
	    set --
	    source /home/$USER/OS-Project_File-System/src/lsDifferent2.sh
	  else
	    source /home/$USER/OS-Project_File-System/src/lsDifferent2.sh "$2"
	  fi
   	;;
  "deleteTag")
    # Delete tag from file case
	  /home/$USER/OS-Project_File-System/src/deleteTag_main $2 $3
   	;;
  "listAll")
   	# List all tags from specific file case
   	/home/$USER/OS-Project_File-System/src/listAll_main $2
   	;;
  *) 
    # Default case: show the usage
    echo "Usage: $0 {help|mkfile|lsDifferent2|deleteTag}"
    exit 0
    ;;
esac

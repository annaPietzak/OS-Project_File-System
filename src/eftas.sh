#!/bin/bash

# Check if at least one argument is given
if [ $# -eq 0 ]; then
  echo "Usage: $0 {help|mkfile|lsDifferent2|deleteTag|newTag|showAvailableTags}"
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
  "newTag")
   	# add a name and vlaue to the known tags
   	/home/$USER/OS-Project_File-System/src/addNewTag_main $2
   	;;
  "showAvailableTags")
   	# prints a list of all available tags
   	/home/$USER/OS-Project_File-System/src/showAvailableTags
   	;;
  *) 
    # Default case: find files and folders with the extended attribute
    echo "Usage: $0 {help|mkfile|lsDifferent2|deleteTag|newTag|showAvailableTags}"
    exit 0
    ;;
esac

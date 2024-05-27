#!/bin/bash

filepath="/home/$USER/OS-Project_File-System/src/help.md"

if [ -f "$filepath" ]; then
  # Opens the file with less so it feels like a man page
  less "$filepath"
else
  echo "Error: File '$filepath' not found."
fi

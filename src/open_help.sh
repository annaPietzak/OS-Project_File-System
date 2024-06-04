#!/bin/bash

filepath="/home/$USER/.eftas/help.md"

if [ -f "$filepath" ]; then
  # Open the file using 'less' for a man page-like experience
  less "$filepath"
else
  echo "Error: File '$filepath' not found."
fi

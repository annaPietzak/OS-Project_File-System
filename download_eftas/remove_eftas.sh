#!/bin/bash

# This bash script deletes all the EFTAS files that were created when running setp_eftas.sh

# Remove hidden eftas folder
rm -dr /home/$USER/.eftas

# Remove eftas bash script again
sudo rm /usr/local/bin/eftas

# Remove the created files when running the makefile
cd ./src/
make clean
cd ..

echo "Removed all compiled files, restored download folder to origin."

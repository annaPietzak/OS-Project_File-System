#!/bin/bash

# This bash script sets up our file system extension for the user, so that he doesn't have
# to do anything.

# Install dependency for setfattr and getfattr (extended attributes)
sudo apt install attr

# Give execution rights to all needed bashscripts
chmod +x ./open_help.sh
chmod +x ./remove_eftas.sh
chmod +x ./eftas.sh
chmod +x ./lsDifferent2.sh

# Compile all files with our makefile
make all

# Create hidden eftas folder
mkdir /home/$USER/.eftas

# Copy all compiled files to the directory /home/$USER/.eftas
cp ./*.o -t /home/$USER/.eftas
cp ./*_main -t /home/$USER/.eftas
cp ./showAvailableTags -t /home/$USER/.eftas
cp ./*.md -t /home/$USER/.eftas
cp ./lsDifferent2.sh -t /home/$USER/.eftas
cp ./open_help.sh -t /home/$USER/.eftas
cp ../ressources/ -r /home/$USER/.eftas

# Move eftas bash script so it can be called like a regular command
sudo cp ./eftas.sh /usr/local/bin/eftas
sudo chmod 755 /usr/local/bin/eftas

echo "Successfully compiled all files, eftas is ready for use now."
echo "Call our extension with 'eftas' to get started."

#!/bin/bash

# This bash script sets up our file system extension for the user, so that he doesn't have
# to do anything.

# Install dependency for setfattr and getfattr (extended attributes)
sudo apt install attr

# Give execution rights to all needed bashscripts
chmod +x ./src/open_help.sh
chmod +x ./remove_eftas.sh
chmod +x ./src/eftas.sh
chmod +x ./src/lsDifferent2.sh

# Compile all files with our makefile
cd ./src
make all
cd ..

# Create hidden eftas folder
mkdir /home/$USER/.eftas

# Copy all compiled files to the directory /home/$USER/.eftas
cp ./src/*.o -t /home/$USER/.eftas
cp ./src/*_main -t /home/$USER/.eftas
cp ./src/showAvailableTags -t /home/$USER/.eftas
cp ./src/*.md -t /home/$USER/.eftas
cp ./src/lsDifferent2.sh -t /home/$USER/.eftas
cp ./src/open_help.sh -t /home/$USER/.eftas
cp ./src/ressources/ -r /home/$USER/.eftas

# Move eftas bash script so it can be called like a regular command
sudo cp ./src/eftas.sh /usr/local/bin/eftas
sudo chmod 755 /usr/local/bin/eftas

echo "Successfully compiled all files, eftas is ready for use now."
echo "Call our extension with 'eftas' to get started."

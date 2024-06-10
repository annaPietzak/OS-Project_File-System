#!/bin/bash

#install dependency for setfattr and gefattrs (extended attributes)
sudo apt install attr

#give execution rights to all bashscripts
chmod +x ./src/open_help.sh
chmod +x ./remove_eftas.sh
chmod +x ./src/eftas.sh
chmod +x ./src/lsDifferent2.sh

#compile all files with makefile
cd ./src
make all
cd ..

#create hidden eftas folder 
mkdir /home/$USER/.eftas

#move all cmopiled files to the directory /home/$USER/.eftas
mv ./src/*.o -t /home/$USER/.eftas
mv ./src/*_main -t /home/$USER/.eftas
mv ./src/showAvailableTags -t /home/$USER/.eftas
mv ./src/*.md -t /home/$USER/.eftas
mv ./src/lsDifferent2.sh -t /home/$USER/.eftas
mv ./src/open_help.sh -t /home/$USER/.eftas
mv ./ressources/ -t /home/$USER/.eftas

#move eftas bash script so it can be called like a command
sudo cp ./src/eftas.sh /usr/local/bin/eftas

echo "Successfully compiled all files, eftas is ready for use. Call with 'eftas'."

#!/bin/bash

#install dependency for setfattr and gefattrs (extended attributes)
sudo apt install attr

#give execution rights to all bashscripts
chmod +x open_help.sh
chmod +x remove_eftas.sh
chmod +x eftas.sh
chmod +x lsDifferent2.sh

#compile all files with makefile
make all

#create hidden eftas folder 
mkdir /home/$USER/.eftas

#copy all cmopiled files to the directory /home/$USER/.eftas
cp ./*.o -t /home/$USER/.eftas
cp ./*_main -t /home/$USER/.eftas
cp ./showAvailableTags -t /home/$USER/.eftas
cp ./*.md -t /home/$USER/.eftas
cp ./lsDifferent2.sh -t /home/$USER/.eftas
cp ./open_help.sh -t /home/$USER/.eftas
cp ../ressources/ -t /home/$USER/.eftas

#move eftas bash script so it can be called like a command
sudo cp eftas.sh /usr/local/bin/eftas

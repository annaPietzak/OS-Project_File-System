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

#move all cmopiled files to the directory /home/$USER/.eftas
mv ./*.o -t /home/$USER/.eftas
mv ./*_main -t /home/$USER/.eftas
mv ./showAvailableTags -t /home/$USER/.eftas
mv ./*.md -t /home/$USER/.eftas
mv ./lsDifferent2.sh -t /home/$USER/.eftas
mv ./open_help.sh -t /home/$USER/.eftas
mv ../ressources/ -t /home/$USER/.eftas

#move eftas bash script so it can be called like a command
sudo cp eftas.sh /usr/local/bin/eftas

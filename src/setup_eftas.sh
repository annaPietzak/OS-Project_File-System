#!/bin/bash

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
#mv ./eftas.sh /

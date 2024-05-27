#!/bin/bash

#compile all files with makefile
make all

#create hidden eftas folder 
mkdir /home/$USER/.eftas

#move all c files to the directory /home/$USER/.eftas
mv ./* -t /home/$USER/.eftas

#move eftas bash script so it can be called like a command
mv ./eftas.sh /
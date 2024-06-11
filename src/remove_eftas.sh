#!/bin/bash

#remove hidden eftas folder
rm -dr /home/$USER/.eftas

#remove eftas bash script again
sudo rm /usr/local/bin/eftas

#remove the created files again
make clean

echo "Removed all compiled files, restored download folder to origin."

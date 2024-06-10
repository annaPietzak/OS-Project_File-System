#!/bin/bash

#move all not compiled files back
mv /home/$USER/.eftas/*.md -t ./
mv /home/$USER/.eftas/lsDifferent2.sh -t ./
mv /home/$USER/.eftas/open_help.sh -t ./
mv /home/$USER/.eftas/ressources/ -t ..

#remove hidden eftas folder
rm -dr /home/$USER/.eftas

#remove eftas bash script again
sudo rm /usr/local/bin/eftas

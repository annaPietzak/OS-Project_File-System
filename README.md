# EFTAS

Welcome to eftas, the "Enhanced File Tagging System". It can be used to add tags to various files and enhance your file management. 


HOW TO SET UP EFTAS?
===============
In order for you to use eftas you need to set it up first. That can be done by running the ```setup_eftas.sh``` file with sudo rights.
The script will compile all scripts, create a ```.eftas``` folder in your user directory and move all compiled files there. This means when eftas is set up by one user on a system, other users cannot use it. 
Sudo rights are required to add the eftas script to your ``/user/local/bin/`` folder. 

HOW TO USE EFTAS?
===============
If the setup was successful, you can now call eftas on the command line with ``eftas``. For more details on the specific use call ``eftas help``.


HOW TO REMOVE EFTAS
================
If you wish to remove eftas, run the ``remove_eftas.sh`` script with sudo rights. It will remove all compiled files and restore the eftas artifacts to how they were before the setup. 


███████╗███████╗████████╗ █████╗ ███████╗ 
██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔════╝ 
█████╗  █████╗     ██║   ███████║███████╗ 
██╔══╝  ██╔══╝     ██║   ██╔══██║╚════██║ 
███████╗██║        ██║   ██║  ██║███████║ 
╚══════╝╚═╝        ╚═╝   ╚═╝  ╚═╝╚══════╝


Welcome to our GitHub page of our file system extension for Linux. It's called enhancing file tagging system
or short EFTAS. With it, you can add extended attributes to different files and then search for only those files.
So for example, if you want to show a friend only certain files, you can use our extension to do so.


Installation:
===============

Following steps are needed to install our extension:
- Download the folder `download_eftas` which contains all the necessary files.
- Move to the downloaded folder.
- Give `setup_eftas.sh` execution rights with the command `chmod +x setup_eftas.sh`.
- Execute `setup_eftas.sh` with `./setup_eftas.sh`. This sets up the extension, so you can call it with `eftas`.


Usage:
===============

If the setup was successful, you can now call EFTAS on the terminal with `eftas`.
For more help on how to use our extension, run `eftas help` on the terminal.


Removal:
===============

If you wish to remove EFTAS, run the `remove_eftas.sh` script with the command `./remove_eftas.sh`.
This will remove all compiled files and restore the EFTAS artifacts to how they were before the setup.


Testing:
===============

If you wish to try our tests, you need to install first the library for CUnit:
```[bash!]
sudo apt install libcunit1 libcunit1-dev
```
Once this is done, head to /src/tests/ and run the Makefile with `make all` to compile and link the files together.
Now you can execute them by running `./test_suite`.


Known Issues:
===============

- When trying to use the command `eftas`, it's possible that it returns "Permission denied". If that's the case,
just run `sudo chmod 755 /usr/local/bin/eftas` to give yourself the correct permissions
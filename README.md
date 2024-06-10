This is our git repository for our OS Project. We're making a file extension that puts tags onto files,
which can be sorted then.

███████╗███████╗████████╗ █████╗ ███████╗
██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔════╝
█████╗  █████╗     ██║   ███████║███████╗
██╔══╝  ██╔══╝     ██║   ██╔══██║╚════██║
███████╗██║        ██║   ██║  ██║███████║
╚══════╝╚═╝        ╚═╝   ╚═╝  ╚═╝╚══════╝

Welcome to our github page of our file system extension for Linux. It's called enhancing file tagging system
or short EFTAS. With it, you can add extended attributes to different files and then search for only those files.
So for example, if you want to show a friend only certain files, you can use our extension to do so.

Installation:
===============

Following steps you have to do to install our extension

To install our extension, you can run `installation.sh` which copies all the necessary files to `home\USER\EFTAS`.

Usage:
===============

To run our extension, you can call `eftas` which shows you the different options you have. Those are:
- mkfile <tag_name> <tag_value> <file_path> -> creates a file with the specified tag_name and tag_value.
  If the file already exists, then it will just add the tag to that file.
- lsDifferent2 <no argument,-a,tag_name> -> shows you files in different ways
    - no argument will utilize the ls command and will show you files in your current directory
    - -a will show you all the files, including the ones that are hidden
    - tag_name will show you the files with that specific tag_name from your current directory and onwards
- deleteTag <tag_name> <file_path> -> deletes the specified tag from the specified file
- listAll <file_path> -> lists all tags that the specified file has



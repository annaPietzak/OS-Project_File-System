
███████╗███████╗████████╗ █████╗ ███████╗
██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔════╝
█████╗  █████╗     ██║   ███████║███████╗
██╔══╝  ██╔══╝     ██║   ██╔══██║╚════██║
███████╗██║        ██║   ██║  ██║███████║
╚══════╝╚═╝        ╚═╝   ╚═╝  ╚═╝╚══════╝


Welcome to our help page. Here you will find all the information you need in order for you to use our extension.
Have fun!


WHAT IS IT?
===============
EFTAS stands for "Enhanced File Tagging System" and can be used to add tags to various files and directories.
With them, you can manage all your different documents and only see that, which you want to see at the moment.


USAGE
===============
Using our extension is very simple. Just type eftas <operation>.

The different operations you can execute are:
- help -> to see this manual page.
- mkfile <tag_name> <tag_value> <file_path> -> creates a file with the specified tagname and -value. If the file already exists, then it will just add the tag to that file. You can only add tags that are known to the filesystem.
- lsDifferent2 <no argument,-a,tag_name> -> shows you files in different ways
	- no argument will utilize the ls command and will show you files in your current directory
	- -a will show you all the files, including the ones that are hidden
	- tag_name will show you the files with that specific tag_name from your current directory and onwards
- deleteTag <tag_name> <file_path> -> deletes the specified tag from the specified file
- listAll <file_path> -> lists all tags that the specified file has
- newTag <tag_name> <tag_value> -> add a new tag to the known tags, so you can add it to a file.
- showAvailableTags -> shows the tags known to the filesystem, all these tags can be added to the filesystem.


BUGS
===============
There are no bugs, just happy little accidents :)


TEAM
===============
We are two computer science students from the University of Basel
and created this file extension as a project for one of our course in Operating Systems.



       /\__/\
      /`    '\
    === 0  0 ===
      \  --  /
     /        \
    /          \
   |            |
    \  ||  ||  /
     \_oo__oo_/#######o

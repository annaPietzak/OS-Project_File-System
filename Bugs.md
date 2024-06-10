# Bugs

* ~~Tagname to long (setxattr: Numerical result out of range)~~
* ~~Tagvalue to long (setxattr: Numerical result out of range)~~
* ~~lsDifferent2 should look at all the files, not only the ones that have a dot in their name~~
* ~~when creating file with mkfile and then looking at it with lsDifferent2, i get user.test="test\000test"
and with getfattr it's user.test~~
* ~~some symbols work with mkfile (ex. %), some don't (ex. #). Don't let them be allowed at all~~
* ~~if tag doesn't exist, then it should return our error, not this (Failed to remove attribute 'user.uni' 
from file 'test.txt': No data available)~~ -> I think it's okay after thinking
* ~~when executing listAll, only shows name but would be nice to see value as well~~
* ~~listAll: when path doesn't exist, this happens (Error when getting size of extended attributes list (listxattr 1))~~
* ~~in eftas.sh all the links are hardcoded. so if it's a different user, then it won't work~~ 
**~~(not quite yet, still have to change paths for the final version)~~**
* ~~in open_help.sh the link to the help.md is hard coded~~
* ~~deleteTag should check length and validity of tagname before doing anything with it~~
* ~~mkfile has to check length of tagValue~~
* ~~split the code in mkfile so that we have a function that we can test and a main method which is being executed~~
* ~~split the code in deleteTag so that we have a function that we can test and a main method which is being executed~~
* ~~split the code in listAll so that we have a function that we can test and a main method which is being executed~~
* ~~when listAll doesn't find any tags, it should say that there aren't any in this file~~
* ~~write help.md file nicer~~
* ~~add documentation and comments to different code files~~
* ~~lsDifferent2 does not show files with tags~~
* ~~maybe rename lsDifferent2 to something more intuitive~~
* ~~add tagFile as an alias to mkfile, it can call the same main method, but would be more intuitive for the user to provide both method names~~
* ~~showAllTags show the last tag twice for some reason~~

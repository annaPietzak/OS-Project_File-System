## Bugs

* ~~Tagname to long (setxattr: Numerical result out of range)~~
* ~~Tagvalue to long (setxattr: Numerical result out of range)~~
* ~~lsDifferent2 should look at all the files, not only the ones that have a dot in their name~~
* ~~when creating file with mkfile and then looking at it with lsDifferent2, i get user.test="test\000test"
and with getfattr it's user.test~~
* ~~some symbols work with mkfile (ex. %), some don't (ex. #). Don't let them be allowed at all~~
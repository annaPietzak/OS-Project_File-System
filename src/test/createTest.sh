#!/bin/bash

# Navigate to the Desktop directory
cd ~/Desktop

# Create the directory structure and files
mkdir -p test/test2/test3

# Execute mkfile.o with the given arguments
./mkfile.o test/test2/test3/test.txt test test
./mkfile.o test/test2/test3/test2.txt test test2
./mkfile.o test/test2/test3/test3.txt test test3
./mkfile.o test/test2/test3/test4.txt test test4
./mkfile.o test/test2/test5.txt test test5
./mkfile.o test/uni.txt uni uni
./mkfile.o test/test.txt test test

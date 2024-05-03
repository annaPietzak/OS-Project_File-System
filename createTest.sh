#!/bin/bash

# Navigate to the Desktop directory
cd ~/Desktop

# Create the directory structure and files
mkdir -p test/test2/test3

# Execute mkfile.o with the given arguments
./mkfile.o test/test2/test3/test.txt test test
./mkfile.o test/uni.txt uni uni

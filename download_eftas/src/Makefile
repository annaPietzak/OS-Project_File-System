# This is the Makefile to compile and link all the single files together so we have working executables

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Object files
MKFILE_MAIN_OBJ = mkfile_main.o mkfile.o isValidString.o checkLengthName.o checkLengthValue.o checkFilePath.o checkIfTagIsKnown.o
DELETE_MAIN_OBJ = deleteTag_main.o deleteTag.o isValidString.o checkLengthName.o
LISTALL_MAIN_OBJ = listAll_main.o listAll.o isValidString.o
NEWTAG_MAIN_OBJ = addNewTag_main.o addNewTag.o isValidString.o checkLengthName.o checkLengthValue.o checkIfTagIsKnown.o
SHOWAVAILABLETAGS_OBJ = showAvailableTags.o

# Executables
MKFILE_MAIN_EXE = mkfile_main
DELETE_MAIN_EXE = deleteTag_main
LISTALL_MAIN_EXE = listAll_main
NEWTAG_MAIN_EXE = newTag_main
SHOWAVAILABLETAGS_EXE = showAvailableTags


# All targets
all: $(MKFILE_MAIN_EXE) $(DELETE_MAIN_EXE) $(LISTALL_MAIN_EXE) $(NEWTAG_MAIN_EXE) $(SHOWAVAILABLETAGS_EXE)

# mkfile executable
$(MKFILE_MAIN_EXE): $(MKFILE_MAIN_OBJ)
	$(CC) $(MKFILE_MAIN_OBJ) -o $(MKFILE_MAIN_EXE)

# deleteTag executable
$(DELETE_MAIN_EXE): $(DELETE_MAIN_OBJ)
	$(CC) $(DELETE_MAIN_OBJ) -o $(DELETE_MAIN_EXE)

# listAll executable
$(LISTALL_MAIN_EXE): $(LISTALL_MAIN_OBJ)
	$(CC) $(LISTALL_MAIN_OBJ) -o $(LISTALL_MAIN_EXE)

# newTag executable
$(NEWTAG_MAIN_EXE): $(NEWTAG_MAIN_OBJ)
	$(CC) $(NEWTAG_MAIN_OBJ) -o $(NEWTAG_MAIN_EXE)

# showAvailableTags executable
$(SHOWAVAILABLETAGS_EXE): $(SHOWAVAILABLETAGS_OBJ)
	$(CC) $(SHOWAVAILABLETAGS_OBJ) -o $(SHOWAVAILABLETAGS_EXE)

# Compile object files
mkfile_main.o: mkfile_main.c include/mkfile.h
	$(CC) $(CFLAGS) -c mkfile_main.c

mkfile.o: mkfile.c include/mkfile.h include/isValidString.h include/checkLengthName.h include/checkLengthValue.h
	$(CC) $(CFLAGS) -c mkfile.c

deleteTag_main.o: deleteTag_main.c include/deleteTag.h
	$(CC) $(CFLAGS) -c deleteTag_main.c

deleteTag.o: deleteTag.c include/deleteTag.h include/isValidString.h
	$(CC) $(CFLAGS) -c deleteTag.c

listAll_main.o: listAll_main.c include/listAll.h
	$(CC) $(CFLAGS) -c listAll_main.c

listAll.o: listAll.c include/isValidString.h
	$(CC) $(CFLAGS) -c listAll.c

isValidString.o: isValidString.c include/isValidString.h
	$(CC) $(CFLAGS) -c isValidString.c

checkLengthName.o: checkLengthName.c include/checkLengthName.h
	$(CC) $(CFLAGS) -c checkLengthName.c

checkLengthValue.o: checkLengthValue.c include/checkLengthValue.h
	$(CC) $(CFLAGS) -c checkLengthValue.c

checkIfTagIsKnown.o: checkIfTagIsKnown.c include/checkIfTagIsKnown.h
	$(CC) $(CFLAGS) -c checkIfTagIsKnown.c

checkFilePath.o: checkFilePath.c include/checkFilePath.h
	$(CC) $(CFLAGS) -c checkFilePath.c

addNewTag_main.o: addNewTag_main.c include/addNewTag.h
	$(CC) $(CFLAGS) -c addNewTag_main.c

addNewTag.o: addNewTag.c include/addNewTag.h
	$(CC) $(CFLAGS) -c addNewTag.c

showAvailableTags.o: showAvailableTags.c include/showAvailableTags.h
	$(CC) $(CFLAGS) -c showAvailableTags.c

# Clean up
clean:
	rm -f *.o $(MKFILE_MAIN_EXE) $(DELETE_MAIN_EXE) $(LISTALL_MAIN_EXE) $(NEWTAG_MAIN_EXE) $(SHOWAVAILABLETAGS_EXE)

.PHONY: all clean

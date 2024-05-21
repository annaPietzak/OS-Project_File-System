# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Object files
MKFILE_MAIN_OBJ = mkfile_main.o mkfile.o isValidString.o checkLengthName.o checkLengthValue.o
DELETE_MAIN_OBJ = deleteTag_main.o deleteTag.o isValidString.o checkLengthName.o
LISTALL_MAIN_OBJ = listAll_main.o listAll.o isValidString.o

# Executables
MKFILE_MAIN_EXE = mkfile_main
DELETE_MAIN_EXE = deleteTag_main
LISTALL_MAIN_EXE = listAll_main

# All targets
all: $(MKFILE_MAIN_EXE) $(DELETE_MAIN_EXE) $(LISTALL_MAIN_EXE)

# mkfile executable
$(MKFILE_MAIN_EXE): $(MKFILE_MAIN_OBJ)
	$(CC) $(MKFILE_MAIN_OBJ) -o $(MKFILE_MAIN_EXE)

# deleteTag executable
$(DELETE_MAIN_EXE): $(DELETE_MAIN_OBJ)
	$(CC) $(DELETE_MAIN_OBJ) -o $(DELETE_MAIN_EXE)

# listAll executable
$(LISTALL_MAIN_EXE): $(LISTALL_MAIN_OBJ)
	$(CC) $(LISTALL_MAIN_OBJ) -o $(LISTALL_MAIN_EXE)

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

# Clean up
clean:
	rm -f *.o $(MKFILE_MAIN_EXE) $(DELETE_MAIN_EXE) $(LISTALL_EXE)

.PHONY: all clean

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Object files
MKFILE_OBJ = mkfile.o isValidString.o checkLengthName.o checkLengthValue.o
DELETE_OBJ = deleteTag.o isValidString.o checkLengthName.o
LISTALL_OBJ = listAll.o

# Executables
MKFILE_EXE = mkfile
DELETE_EXE = deleteTag
LISTALL_EXE = listAll

# All targets
all: $(MKFILE_EXE) $(DELETE_EXE) $(LISTALL_EXE)

# mkfile executable
$(MKFILE_EXE): $(MKFILE_OBJ)
	$(CC) $(MKFILE_OBJ) -o $(MKFILE_EXE)

# deleteTag executable
$(DELETE_EXE): $(DELETE_OBJ)
	$(CC) $(DELETE_OBJ) -o $(DELETE_EXE)

# listAll executable
$(LISTALL_EXE): $(LISTALL_OBJ)
	$(CC) $(LISTALL_OBJ) -o $(LISTALL_EXE)

# Compile object files
mkfile.o: mkfile.c include/isValidString.h include/checkLengthName.h include/checkLengthValue.h
	$(CC) $(CFLAGS) -c mkfile.c

deleteTag.o: deleteTag.c include/isValidString.h
	$(CC) $(CFLAGS) -c deleteTag.c

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
	rm -f *.o $(MKFILE_EXE) $(DELETE_EXE) $(LISTALL_EXE)

.PHONY: all clean

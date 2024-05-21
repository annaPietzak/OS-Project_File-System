# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../include
LDFLAGS = -lcunit
SRC = 	../checkLengthName.c \
		../checkLengthValue.c \
		test_check_tag.c \
		../isValidString.c \
		test_is_valid_string.c \
		test_mkfile.c \
		../mkfile.c \
		test_deleteTag.c \
		../deleteTag.c \
		test_listAll.c \
		../listAll.c \
		test_suite.c
OBJ = $(SRC:.c=.o)
EXEC = test_suite

# Targets
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

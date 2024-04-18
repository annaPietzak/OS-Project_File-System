all: mkfile list listAll delete search

mkfile:
	gcc mkfile.c -o mkfile.o
list:
	gcc list.c -o list.o
listAll:
	gcc listAll.c -o listAll.o
delete:
	gcc deleteTag.c -o deleteTag.o
search:
	gcc searchTag.c -o searchTag.o
clean:
	rm *.o
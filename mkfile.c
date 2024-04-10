#include <fcntl.h>
#include <sys/xattr.h>
#include <string.h>
#include <stddef.h>
#include <attr/attributes.h>


int main (int argc, char * argv[]) {
	int fd2 = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);

	//attr_set (argv[1], "tag", argv[2], strlen(argv[2]), NULL);
	setxattr(argv[1], "tag", argv[2], strlen(argv[2]), 0);
}

#include <fcntl.h>
#include <sys/xattr.h>
#include <sys/types.h>
#include <string.h>
#include <stddef.h>
#include <attr/attributes.h>
#include <stdio.h>

int main (int argc, char * argv[]) {
	char* attr[strlen("educationXXX")];
	listxattr(argv[1], *attr, strlen("educationXXX"));
	printf("attributes: %s\n", *attr);

	getxattr(argv[1], "tag", *attr, strlen("educationXXX"));
	printf("attributes: %s\n", *attr);
}




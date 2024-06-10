#ifndef LISTALL_H
#define LISTALL_H

#include <sys/xattr.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_ATTR_VALUE_SIZE 3073

int list_all_tags(const char * filePath);

#endif //LISTALL_H

#ifndef DELETETAG_H
#define DELETETAG_H

#include <sys/xattr.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "isValidString.h"
#include "checkLengthName.h"

#define MAX_ATTR_NAME_SIZE 255

int delete_tag_from_file(const char * tagName, const char * filePath);

#endif //DELETETAG_H

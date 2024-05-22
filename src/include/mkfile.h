#ifndef MKFILE_H
#define MKFILE_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <unistd.h>
#include "isValidString.h"
#include "checkLengthName.h"
#include "checkLengthValue.h"

int create_file_with_attribute(const char *tagName, const char *tagValue, const char *filePath);

#endif //MKFILE_H

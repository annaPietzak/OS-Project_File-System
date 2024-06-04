#ifndef ADDNEWTAG_H
#define ADDNEWTAG_H

#include <sys/stat.h>
// #include <cstdio>
#include <stdio.h>
#include <stdbool.h>
#include "isValidString.h"
#include "checkLengthName.h"
#include "checkLengthValue.h"
#include "checkIfTagIsKnown.h"

int add_new_tag(const char * tagName, const char * tagValue);

#endif //ADDNEWTAG_H

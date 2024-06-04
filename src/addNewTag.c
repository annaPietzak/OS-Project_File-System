#include "include/addNewTag.h"

int add_new_tag(const char * tagName, const char * tagValue) {
    FILE * fp;
//    char * line = NULL;
//    size_t len = 0;
//    ssize_t read;
//    bool found = false;

    fp = fopen("ressources/tags.csv", "r");
    if (fp == NULL)
        return 1;

    fprintf(fp, "%s; %s\n", tagName, tagValue);
   
    fclose(fp);
   
    return(0);

//    if (line)
//        free(line);
}

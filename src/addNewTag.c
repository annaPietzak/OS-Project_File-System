#include "include/addNewTag.h"

int add_new_tag(const char * tagName) {
    printf("Add tag %s to the system\n", tagName);
    FILE * fp;

    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "a");
    if (fp == NULL)
        return 1;

    fprintf(fp, "%s\n", tagName);

    fclose(fp);
    printf("Tag %s is added to system.\n", tagName);
    return(0);
}

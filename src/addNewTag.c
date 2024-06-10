#include "include/addNewTag.h"

int add_new_tag(const char * tagName, const char * tagValue) {
    printf("add tag to system.\n");
    FILE * fp;

    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "a");
    if (fp == NULL)
        return 1;

    fprintf(fp, "%s; %s\n", tagName, tagValue);

    fclose(fp);
    printf("tag added to system.\n");
    return(0);
}

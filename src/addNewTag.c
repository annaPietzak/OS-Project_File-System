#include "include/addNewTag.h"

int add_new_tag(const char * tagName, const char * tagValue) {
    printf("add tag to system.\n");
    FILE * fp;

    fp = fopen("/home/$USER/.eftas/ressources/tags.csv", "a");
    if (fp == NULL)
        return 1;

    fprintf(fp, "%s; %s\n", tagName, tagValue);

    fclose(fp);
    printf("tag added to system.\n");
    return(0);
}

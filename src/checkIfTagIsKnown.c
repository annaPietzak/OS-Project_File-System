#include "include/checkIfTagIsKnown.h"


// Check if path points to file and not directory
int check_if_tag_is_known(const char * tagName, const char * tagValue) {
    FILE * fp;
    char line[1000];
    char inputTag[1000];
    strcpy(inputTag, tagName);
    strcat(inputTag, "; ");
    strcat(inputTag, tagValue);
    bool found = false;

    char pathToTags[] = "/home/";
    strcat(pathToTags, getenv("USERNAME");
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "r");
    if (fp == NULL)
        return 1;

    while (feof(fp) != true){
        fgets(line, 1000, fp);
        //printf("Tag: %s\n", line);
        if (strcmp(line, inputTag) == 0) {
            found = true;
            break;
        }
    }

    fclose(fp);
    if (found) {
        //printf("Tag exists! \n");
        return 0;
    } else {
        //printf("Tag does not exists! \n");
        return 1;
    }
}

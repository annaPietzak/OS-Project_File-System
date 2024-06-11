#include "include/checkIfTagIsKnown.h"

// Check if path points to file and not directory
int check_if_tag_is_known(const char * tagName) {
    FILE * fp;
    char line[256];
    char inputTag[256];
    strcpy(inputTag, tagName);
    strcat(inputTag, "\n");
    printf("%s", inputTag);
    bool found = false;

    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "r");
    if (fp == NULL){
	    printf("error - tags not found\n");
        return 1;
    }

    while (fgets (line, 256, fp)!= NULL){
        //printf("Tag: %s", line);
        if (strcmp(line, inputTag) == 0) {
            //printf("Found it\n");
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

#include "include/checkIfTagIsKnown.h"


// Check if path points to file and not directory
int check_if_tag_is_known(const char * tagName, const char * tagValue) {
//    printf("searching tag ");
    FILE * fp;
    char line[1000];
    char inputTag[1000];
    strcpy(inputTag, tagName);
    strcat(inputTag, "; ");
    strcat(inputTag, tagValue);
    strcat(inputTag, "\n");
    printf("%s", inputTag);
    bool found = false;

    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
//    printf("%s\n",pathToTags);
    fp = fopen(pathToTags, "r");
//    fp = fopen("/home/anna/.eftas/ressources/tags.csv", "r");
    if (fp == NULL){
	    printf("error - tags not found\n");
        return 1;
    }

    while (feof(fp) != true){
        fgets(line, 1000, fp);
//        printf("Tag: %s", line);
        if (strcmp(line, inputTag) == 0) {
            found = true;
            break;
        }
    }

    fclose(fp);
    if (found) {
//        printf("Tag exists! \n");
        return 0;
    } else {
//        printf("Tag does not exists! \n");
        return 1;
    }
}

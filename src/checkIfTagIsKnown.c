#include "include/checkIfTagIsKnown.h"


// Check if path points to file and not directory
int check_if_tag_is_known(const char * tagName, const char * tagValue) {
    FILE * fp;
    //char * line = NULL;
    char line[1000];
    char inputTag[1000];
    strcpy(inputTag, tagName);
    strcat(inputTag, "; ");
    strcat(inputTag, tagValue);
//    size_t len = 0;
//    size_t read;
    bool found = false;

    fp = fopen("ressources/tags.csv", "r");
    if (fp == NULL)
        return 1;

    while (feof(fp) != true){
        fgets(line, 1000, fp);
        //printf("Tag: %s", line);
        if (strcmp(line, inputTag)) {
            found = true;
            break;
        }
    }

//    while ((read = getline(&line, &len, fp)) != -1) {
//        if (strcmp(line, (tagName) + "; " + (tagValue))) {
//            found = true;
//            break;
//        }
//    }

    fclose(fp);
//    if (line)
//        free(line);
    
    if (found) {
        return 0;
    } else {
        return 1;
    }
}

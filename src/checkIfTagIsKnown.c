#include "include/checkIfTagIsKnown.h"

/**
 * This method goes through our tags.csv file, which contains all known tags and checks,
 * if the tag, that the user wants to use, is in the list or not. If yes, then the tag gets
 * added to the file. If not, then does the user have to first use newTag to add the tag to
 * the known tags (gets put into tags.csv).
 * @param tagName name of the tag that should be checked
 * @return 0 or 1 depending on if it was found or not
 */

int check_if_tag_is_known(const char * tagName) {
    FILE * fp;
    char line[256];
    char inputTag[256];
    strcpy(inputTag, tagName);
    strcat(inputTag, "\n");
    printf("%s", inputTag);
    bool found = false;

    // Create the path to tags.csv
    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "r");
    if (fp == NULL){
	    printf("error - tags not found\n");
        return 1;
    }

    // Go over the list to see, if the tag is known or not
    while (fgets (line, 256, fp)!= NULL){
        //printf("Tag: %s", line);
        if (strcmp(line, inputTag) == 0) {
            //printf("Found it\n");
            found = true;
            break;
        }
    }

    // Return if it was found (0) or not (1)
    fclose(fp);
    if (found) {
        //printf("Tag exists!\n");
        return 0;
    } else {
        //printf("Tag does not exists!\n");
        return 1;
    }
}

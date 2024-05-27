#include "include/checkIfTagIsKnown.h"


// Check if path points to file and not directory
int check_if_tag_is_known(const char * tagName, const char * tagValue) {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    boolean found = false;

    fp = fopen("ressources/tags.csv", "r");
    if (fp == NULL)
        exit(1);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strcmp(line, tagName + ";" + tagValue)) {
            found = true;
            break;
        }
    }

    fclose(fp);
    if (line)
        free(line);
    
    if (found) {
        return 0;
    } else {
        return 1;
    }
}

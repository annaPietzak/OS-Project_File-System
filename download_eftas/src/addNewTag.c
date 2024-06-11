#include "include/addNewTag.h"

/**
 * This method adds a tag to our tags.csv file, which contains all the known tags
 * @param tagName name of the tag that should be written to the file
 * @return 0 or 1 depending on if it worked or not
 */

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

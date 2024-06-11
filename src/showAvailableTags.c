#include "include/showAvailableTags.h"

/**
 * This is the main method which shows all the tags that are in the tags.csv file. The ones
 * that are shown are able to be used. If you want to use more, you can use newTag to add
 * another tagName to the file.
 * @return 0 or 1 depending on if it worked or not
 */

int main() {
    FILE * fp;
    char line[256];

    // Create the path to the file tags.csv
    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "r");

    // tags.csv either wasn't found or something else went wrong when accessing it
    if (fp == NULL){
        printf("error - tags not found\n");
        return 1;
    }

    // Lists all the available tags
    printf("Available tags: \n");
    while (fgets (line, 256, fp)!= NULL){
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}

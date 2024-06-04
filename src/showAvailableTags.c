#include "include/showAvailableTags.h"


// Check if path points to file and not directory
int show_available_tags() {
    FILE * fp;
    char * line = NULL;
    char * allTags = "Available tags \n";
    size_t len = 0;
    ssize_t read;
    boolean found = false;

    fp = fopen("ressources/tags.csv", "r");
    if (fp == NULL)
        exit(1);

    while ((read = getline(&line, &len, fp)) != -1) {
        allTags = allTags + line + "\n";
    }

    echo allTags;

    fclose(fp);
    if (line)
        free(line);
    return 0;
}

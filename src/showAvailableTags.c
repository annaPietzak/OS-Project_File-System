#include "include/showAvailableTags.h"


// Check if path points to file and not directory
int show_available_tags() {
    FILE * fp;
    char line[1000];

    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "r");

    if (fp == NULL){
        printf("error - tags not found\n");
        return 1;
    }
    
    printf("Available tags: \n");
    while (feof(fp) != true){
        fgets(line, 1000, fp);
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}

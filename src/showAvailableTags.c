#include "include/showAvailableTags.h"


// Check if path points to file and not directory
int main() {
    FILE * fp;
    char line[3500];

    char pathToTags[100] = "/home/";
    strcat(pathToTags, getenv("USERNAME"));
    strcat(pathToTags, "/.eftas/ressources/tags.csv");
    fp = fopen(pathToTags, "r");

    if (fp == NULL){
        printf("error - tags not found\n");
        return 1;
    }

    printf("Available tags: \n");
    while (fgets (line, 3500, fp)!= NULL){
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}

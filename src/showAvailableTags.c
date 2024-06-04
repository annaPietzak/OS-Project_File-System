#include "include/showAvailableTags.h"


// Check if path points to file and not directory
int show_available_tags() {
    FILE * fp;
    char * line = NULL;

    fp = fopen("ressources/tags.csv", "r");
    if (fp == NULL)
        return 1;

    while (feof(fp) != true){
        fgets(line, 1000, fp);
        printf("Tag: %s", line);
    }

    fclose(fp);
//    if (line)
//        free(line);
    return 0;
}

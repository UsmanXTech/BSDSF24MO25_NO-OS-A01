#include "myfilefunctions.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int wordCount(const char *filename)
{
    FILE *file;
    int ch;
    int words = 0;
    int in_word = 0;

    if (filename == NULL)
        return -1;

    file = fopen(filename, "r");
    if (file == NULL)
        return -1;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    fclose(file);
    return words;
}

int mygrep(const char *filename, const char *pattern)
{
    FILE *file;
    char line[1024];
    int matches = 0;

    if (filename == NULL || pattern == NULL)
        return -1;

    file = fopen(filename, "r");
    if (file == NULL)
        return -1;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            fputs(line, stdout);
            matches++;
        }
    }

    fclose(file);
    return matches;
}

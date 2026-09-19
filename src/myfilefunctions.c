#include "myfilefunctions.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int wordCount(FILE *file, int *lines, int *words, int *chars)
{
    int ch;
    int in_word = 0;

    if (file == 0 || lines == 0 || words == 0 || chars == 0)
        return -1;

    *lines = 0;
    *words = 0;
    *chars = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;

        if (ch == '\n')
            (*lines)++;

        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            (*words)++;
        }
    }

    if (ferror(file))
        return -1;

    return 0;
}

int mygrep(FILE *fp, const char *search_str, char ***matches)
{
    char buffer[1024];
    char **result = 0;
    int count = 0;

    if (fp == 0 || search_str == 0 || matches == 0)
        return -1;

    *matches = 0;

    while (fgets(buffer, sizeof(buffer), fp) != 0) {
        if (strstr(buffer, search_str) != 0) {
            char **new_result;
            char *line_copy;
            size_t length = strlen(buffer);

            line_copy = malloc(length + 1);
            if (line_copy == 0) {
                int i;
                for (i = 0; i < count; i++)
                    free(result[i]);
                free(result);
                return -1;
            }

            memcpy(line_copy, buffer, length + 1);

            new_result = realloc(result, (size_t)(count + 1) * sizeof(*result));
            if (new_result == 0) {
                free(line_copy);
                {
                    int i;
                    for (i = 0; i < count; i++)
                        free(result[i]);
                }
                free(result);
                return -1;
            }

            result = new_result;
            result[count] = line_copy;
            count++;
        }
    }

    if (ferror(fp)) {
        int i;
        for (i = 0; i < count; i++)
            free(result[i]);
        free(result);
        return -1;
    }

    *matches = result;
    return count;
}

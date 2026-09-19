#include <stdio.h>
#include <stdlib.h>

#include "mystrfunctions.h"
#include "myfilefunctions.h"

int main(void)
{
    char copied[64];
    char combined[128];
    FILE *file;
    char **matches = 0;
    int lines;
    int words;
    int chars;
    int match_count;
    int i;

    if (mystrcpy(copied, "Operating Systems") != 0)
        return 1;

    if (mystrcpy(combined, "Day 2: ") != 0)
        return 1;

    if (mystrcat(combined, copied) != 0)
        return 1;

    printf("String: %s\n", combined);
    printf("Length: %d\n", mystrlen(combined));

    if (mystrncpy(copied, "Multi-file C", (int)sizeof(copied) - 1) != 0)
        return 1;

    copied[sizeof(copied) - 1] = '\0';
    printf("Copied: %s\n", copied);

    file = tmpfile();
    if (file == 0)
        return 1;

    fputs("Operating Systems\n", file);
    fputs("Multi-file C project\n", file);
    fputs("Static library comes next\n", file);
    rewind(file);

    if (wordCount(file, &lines, &words, &chars) != 0) {
        fclose(file);
        return 1;
    }

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    rewind(file);
    match_count = mygrep(file, "library", &matches);
    if (match_count < 0) {
        fclose(file);
        return 1;
    }

    printf("Matches: %d\n", match_count);
    for (i = 0; i < match_count; i++) {
        printf("%s", matches[i]);
        free(matches[i]);
    }

    free(matches);
    fclose(file);

    return 0;
}

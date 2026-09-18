#include <stdio.h>
#include "mystrfunctions.h"
#include "myfilefunctions.h"

int main(void)
{
    char copied[64];
    char combined[128];

    mystrcpy(copied, "Operating Systems");
    mystrcpy(combined, "Day 2: ");
    mystrcat(combined, copied);

    printf("String: %s\n", combined);
    printf("Length: %zu\n", mystrlen(combined));

    mystrncpy(copied, "Multi-file C", sizeof(copied) - 1);
    copied[sizeof(copied) - 1] = '\0';
    printf("Copied: %s\n", copied);

    printf("wordCount and mygrep are available through the file utility module.\n");

    return 0;
}

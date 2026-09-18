#include "mystrfunctions.h"

size_t mystrlen(const char *str)
{
    size_t length = 0;

    if (str == NULL)
        return 0;

    while (str[length] != '\0')
        length++;

    return length;
}

char *mystrcpy(char *dest, const char *src)
{
    char *start = dest;

    if (dest == NULL || src == NULL)
        return dest;

    while ((*dest++ = *src++) != '\0')
        ;

    return start;
}

char *mystrncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    if (dest == NULL || src == NULL)
        return dest;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (; i < n; i++)
        dest[i] = '\0';

    return dest;
}

char *mystrcat(char *dest, const char *src)
{
    char *start = dest;

    if (dest == NULL || src == NULL)
        return dest;

    while (*dest != '\0')
        dest++;

    while ((*dest++ = *src++) != '\0')
        ;

    return start;
}

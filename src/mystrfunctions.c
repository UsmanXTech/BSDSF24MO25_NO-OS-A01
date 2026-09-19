#include "mystrfunctions.h"

int mystrlen(const char *s)
{
    int length = 0;

    if (s == 0)
        return -1;

    while (s[length] != '\0')
        length++;

    return length;
}

int mystrcpy(char *dest, const char *src)
{
    int i = 0;

    if (dest == 0 || src == 0)
        return -1;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return 0;
}

int mystrncpy(char *dest, const char *src, int n)
{
    int i;

    if (dest == 0 || src == 0 || n < 0)
        return -1;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (; i < n; i++)
        dest[i] = '\0';

    return 0;
}

int mystrcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    if (dest == 0 || src == 0)
        return -1;

    while (dest[i] != '\0')
        i++;

    while (src[j] != '\0') {
        dest[i++] = src[j++];
    }

    dest[i] = '\0';
    return 0;
}

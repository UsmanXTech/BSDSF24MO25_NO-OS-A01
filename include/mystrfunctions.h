#ifndef MYSTRFUNCTIONS_H
#define MYSTRFUNCTIONS_H

#include <stddef.h>

size_t mystrlen(const char *str);
char *mystrcpy(char *dest, const char *src);
char *mystrncpy(char *dest, const char *src, size_t n);
char *mystrcat(char *dest, const char *src);

#endif

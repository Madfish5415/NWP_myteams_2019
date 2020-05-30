/*
** EPITECH PROJECT, 2020
** libxml3
** File description:
** params.c
*/

#include <stdlib.h>
#include <string.h>

#include "libxml3.h"

static char *getValue(char *str)
{
    int len = 0;
    char *result = NULL;

    if (!str) return NULL;
    for (int i = 0;  str[i] && str[i] != '\"' && str[i] != '\n'; i++, len++);
    result = strndup(str, len);
    return result;
}

void setParams(char *content, xmlDocPtr doc)
{
    if (!content) return;
    if (strncmp(content, "<?", 2) != 0) return;
    for (int i = 0; content[i] && content[i] != '\n'; i++) {
        if (strncmp(&content[i], "version=\"", 9) == 0)
            doc->version = getValue(&content[i + 9]);
        if (strncmp(&content[i], "encoding=\"", 10) == 0)
            doc->encoding = getValue(&content[i + 10]);
    }
}
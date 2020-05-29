/*
** EPITECH PROJECT, 2020
** libxml3
** File description:
** root.c
*/

#include <stdlib.h>
#include <string.h>

#include "libxml3.h"

char *getRootElem(char *content)
{
    int len = 0;

    if (!content) return NULL;
    if (strncmp(content, "<?", 2) != 0) return content;
    for (int i = 0; content[i] && content[i] != '\n'; i++, len++);
    if (content[len] == '\0')
        return NULL;
    return &content[len + 1];
}
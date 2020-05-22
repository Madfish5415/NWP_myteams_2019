/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_format_string.c
*/

#include <stdlib.h>
#include <string.h>

#include "utils.h"

char *format_string(char *string)
{
    char **tab = NULL;
    char *format = NULL;
    unsigned long len = 0;

    tab = split(strdup(string), " ");
    if (!tab)
        return NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        len = ((format) ? strlen(format) : 0);
        format = realloc(format, sizeof(char) * (len + strlen(tab[i]) + 4));
        if (!format)
            return NULL;
        format = strcat(format, tab[i]);
        format = strcat(format, "\r\n\0");
        format[len + strlen(tab[i]) + 4] = '\0';
    }
    return format;
}
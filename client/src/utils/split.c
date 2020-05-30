/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** split.c
*/

#include <stdlib.h>
#include <string.h>

char **split(char *str, char *delim)
{
    char *split_str = strtok(str, delim);
    char **result = NULL;
    int i = 0;

    for (i = 1; split_str != NULL; i++) {
        if ((result = realloc(result, sizeof(char *) * (i + 1))) == NULL)
            return NULL;
        result[i - 1] = strdup(split_str);
        split_str = strtok(NULL, delim);
    }
    if (result != NULL)
        result[i - 1] = NULL;
    return (result);
}
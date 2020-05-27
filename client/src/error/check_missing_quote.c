/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** check_missing_quote.c
*/

#include <string.h>
#include <stdio.h>

#include "exception.h"
#include "utils.h"

bool check_missing_quote(const char *string)
{
    char **tab = NULL;
    int nb_quote = 0;
    int nb_args = 0;
    char *tmp = NULL;

    if (string[0] == 0)
        return false;
    tmp = strdup(string);
    tab = split(tmp, " ");
    if (!tab) return false;
    for (; tab[nb_args]; nb_args++);
    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++)
            nb_quote += (tab[i][j] == '"');
    if (nb_quote != ((nb_args - 1) * 2)) {
        printf("Invalid argument.\n");
        free(tmp);
        return false;
    } free(tmp);
    return true;
}
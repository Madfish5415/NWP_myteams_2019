/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_users.c
*/

#include <stdlib.h>

#include "logging_client.h"

void cli_print_users(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    for (; tab[i] != NULL; i++);
    for (int j = 1; j < i; j += 3) {
        client_print_users(tab[i], tab[i + 1], atoi(tab[i + 2]));
    }
}
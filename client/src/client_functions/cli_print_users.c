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
    if (!tab)
        return;
    for (int i = 1; tab[i] != NULL; i += 3) {
        client_print_users(tab[i], tab[i + 1], atoi(tab[i + 2]));
    }
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_teams.c
*/

#include "logging_client.h"

void cli_print_teams(char **tab)
{
    if (!tab)
        return;
    for (int i = 1; tab[i] != NULL; i += 3) {
        client_print_teams(tab[i], tab[i + 1], tab[i + 2]);
    }
}
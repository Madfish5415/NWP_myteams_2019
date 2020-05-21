/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_team_print_channels.c
*/

#include <stdlib.h>

#include "logging_client.h"

void cli_team_print_channels(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    for (; tab[i] != NULL; i++);
    for (int j = 1; j < i; j += 3) {
        client_team_print_channels(tab[i], tab[i + 1], tab[i + 2]);
    }
}
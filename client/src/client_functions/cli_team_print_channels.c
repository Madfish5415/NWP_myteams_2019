/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_team_print_channels.c
*/

#include <stdlib.h>

#include "logging_client.h"
#include "utils.h"

void cli_team_print_channels(char **tab)
{
    if (!tab)
        return;
    for (int i = 1; tab[i] != NULL; i += 3) {
        client_team_print_channels(tab[i], tab[i + 1], tab[i + 2]);
    }
}
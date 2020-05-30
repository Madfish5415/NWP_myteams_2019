/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_team_print_channels.c
*/

#include <stdlib.h>

#include "logging_client.h"

char **cli_team_print_channels(char **tab)
{
    if (!tab)
        return NULL;
    client_team_print_channels(tab[1], tab[2], tab[3]);
    return &tab[4];
}
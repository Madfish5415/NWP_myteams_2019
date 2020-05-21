/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_unkonw_team.c
*/

#include "logging_client.h"

void cli_error_unknown_team(char **tab)
{
    if (!tab)
        return;
    client_error_unknown_team(tab[1]);
}
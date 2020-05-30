/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_team_created.c
*/

#include "logging_client.h"

char **cli_event_team_created(char **tab)
{
    if (!tab)
        return NULL;
    client_event_team_created(tab[1], tab[2], tab[3]);
    return &tab[4];
}
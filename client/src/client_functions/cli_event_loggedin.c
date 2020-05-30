/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_loggedin.c
*/

#include "logging_client.h"

char **cli_event_loggedin(char **tab)
{
    if (!tab)
        return NULL;
    client_event_loggedin(tab[1], tab[2]);
    return &tab[3];
}
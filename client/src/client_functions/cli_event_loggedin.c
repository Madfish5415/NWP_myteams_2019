/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_loggedin.c
*/

#include "logging_client.h"

void cli_event_loggedin(char **tab)
{
    if (tab)
        client_event_loggedin(tab[1], tab[2]);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_loggedout.c
*/

#include "logging_client.h"

void cli_event_loggedout(char **tab)
{
    if (tab)
        client_event_loggedout(tab[1], tab[2]);
}
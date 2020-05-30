/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_loggedout.c
*/

#include "logging_client.h"
#include "client.h"

char **cli_event_loggedout(char **tab)
{
    if (!tab)
        return NULL;
    client_event_loggedout(tab[1], tab[2]);
    return &tab[3];
}
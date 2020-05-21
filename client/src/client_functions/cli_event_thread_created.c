/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_thread_created.c
*/

#include <stdlib.h>

#include "logging_client.h"

void cli_event_thread_created(char **tab)
{
    if (tab)
        client_event_thread_created(
            tab[1], tab[2], atoi(tab[3]), tab[4], tab[5]);
}
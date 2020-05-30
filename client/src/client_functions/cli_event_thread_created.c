/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_thread_created.c
*/

#include "logging_client.h"
#include "utils.h"

char **cli_event_thread_created(char **tab)
{
    if (!tab)
        return NULL;
    client_event_thread_created(
        tab[1], tab[2], strptime(tab[3]), tab[4], tab[5]);
    return &tab[6];
}
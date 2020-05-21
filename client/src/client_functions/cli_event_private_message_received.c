/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_event_private_message_received.c
*/

#include "logging_client.h"

void cli_event_private_message_received(char **tab)
{
    if (tab)
        client_event_private_message_received(tab[1], tab[2]);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_private_message_print_messages.c
*/

#include <stdlib.h>

#include "logging_client.h"

void cli_private_message_print_messages(char **tab)
{
    if (!tab)
        return;
    for (int i = 1; tab[i] != NULL; i += 4) {
        client_private_message_print_messages(
            tab[i], atoi(tab[i + 1]), tab[i + 2]);
    }
}
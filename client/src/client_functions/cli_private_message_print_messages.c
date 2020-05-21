/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_private_message_print_messages.c
*/

#include "logging_client.h"
#include "utils.h"

void cli_private_message_print_messages(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    for (; tab[i] != NULL; i++);
    for (int j = 1; j < i; j += 3) {
        client_private_message_print_messages(
            tab[i], strptime(tab[i + 1]), tab[i + 2]);
    }
}
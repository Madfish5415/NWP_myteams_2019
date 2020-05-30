/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_private_message_print_messages.c
*/

#include "logging_client.h"
#include "utils.h"

char **cli_private_message_print_messages(char **tab)
{
    if (!tab)
        return NULL;
    client_private_message_print_messages(tab[1], strptime(tab[2]), tab[3]);
    return &tab[4];
}
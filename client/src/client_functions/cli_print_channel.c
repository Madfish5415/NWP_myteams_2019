/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_channel.c
*/

#include "logging_client.h"

void cli_print_channel(char **tab)
{
    if (!tab)
        return;
    client_print_channel(tab[1], tab[2], tab[3]);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_unknown_channel.c
*/

#include "logging_client.h"
#include "utils.h"

void cli_error_unknown_channel(char **tab)
{
    if (!tab)
        return;
    client_error_unknown_channel(tab[1]);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_unknown_thread.c
*/

#include "logging_client.h"

void cli_error_unknown_thread(char **tab)
{
    if (!tab)
        return;
    client_error_unknown_thread(tab[1]);
}
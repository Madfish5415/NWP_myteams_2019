/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_unknown_thread.c
*/

#include "logging_client.h"

char **cli_error_unknown_thread(char **tab)
{
    if (!tab)
        return NULL;
    client_error_unknown_thread(tab[1]);
    return &tab[2];
}
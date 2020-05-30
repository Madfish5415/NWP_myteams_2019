/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_unknown_user.c
*/

#include "logging_client.h"

char **cli_error_unknown_user(char **tab)
{
    if (!tab)
        return NULL;
    client_error_unknown_user(tab[1]);
    return &tab[2];
}
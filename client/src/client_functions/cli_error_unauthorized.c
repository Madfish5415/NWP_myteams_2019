/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_unauthorized.c
*/

#include "logging_client.h"

char **cli_error_unauthorized(char **tab)
{
    if (!tab)
        return NULL;
    client_error_unauthorized();
    return &tab[1];
}
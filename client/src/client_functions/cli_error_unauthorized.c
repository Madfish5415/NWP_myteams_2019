/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_unauthorized.c
*/

#include "logging_client.h"
#include "utils.h"

void cli_error_unauthorized(char **tab)
{
    (void) tab;
    client_error_unauthorized();
}
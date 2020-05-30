/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_error_already_exist.c
*/

#include "logging_client.h"

char **cli_error_already_exist(char **tab)
{
    if (!tab)
        return NULL;
    client_error_already_exist();
    return &tab[1];
}
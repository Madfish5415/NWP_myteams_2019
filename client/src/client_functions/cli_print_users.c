/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_users.c
*/

#include <stdlib.h>

#include "logging_client.h"

char **cli_print_users(char **tab)
{
    if (!tab)
        return NULL;
    client_print_users(tab[1], tab[2], atoi(tab[3]));
    return &tab[4];
}
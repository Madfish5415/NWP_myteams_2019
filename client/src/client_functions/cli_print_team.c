/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_team.c
*/

#include "logging_client.h"

char **cli_print_team(char **tab)
{
    if (!tab)
        return NULL;
    client_print_team(tab[1], tab[2], tab[3]);
    return &tab[4];
}
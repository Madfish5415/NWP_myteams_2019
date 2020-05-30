/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_unsubscribed.c
*/

#include "logging_client.h"

char **cli_print_unsubscribed(char **tab)
{
    if (!tab)
        return NULL;
    client_print_unsubscribed(tab[1], tab[2]);
    return &tab[3];
}
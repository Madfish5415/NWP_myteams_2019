/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_subscribed.c
*/

#include "logging_client.h"

void cli_print_subscribed(char **tab)
{
    if (!tab)
        return;
    client_print_subscribed(tab[1], tab[2]);
}
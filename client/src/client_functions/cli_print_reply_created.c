/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_reply_created.c
*/

#include <stdlib.h>

#include "logging_client.h"

void cli_print_reply_created(char **tab)
{
    if (!tab)
        return;
    client_print_reply_created(tab[1], tab[2], atoi(tab[3]), tab[4]);
}
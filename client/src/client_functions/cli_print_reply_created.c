/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_reply_created.c
*/

#include "logging_client.h"
#include "utils.h"

char **cli_print_reply_created(char **tab)
{
    if (!tab)
        return NULL;
    client_print_reply_created(tab[1], tab[2], strptime(tab[3]), tab[4]);
    return &tab[5];
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_thread_print_replies.c
*/

#include "logging_client.h"
#include "utils.h"

char **cli_thread_print_replies(char **tab)
{
    if (!tab)
        return NULL;
    client_thread_print_replies(tab[1], tab[2], strptime(tab[3]), tab[4]);
return &tab[5];
}
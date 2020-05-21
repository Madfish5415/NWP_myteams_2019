/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_thread_print_replies.c
*/

#include <stdlib.h>

#include "logging_client.h"
#include "utils.h"

void cli_thread_print_replies(char **tab)
{
    if (!tab)
        return;
    for (int i = 1; tab[i] != NULL; i += 4) {
        client_thread_print_replies(
            tab[i], tab[i + 1], atoi(tab[i + 2]), tab[i + 3]);
    }
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_thread_print_replies.c
*/

#include <stdlib.h>

#include "logging_client.h"

void cli_thread_print_replies(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    for (; tab[i] != NULL; i++);
    for (int j = 1; j < i; j += 4) {
        client_thread_print_replies(
            tab[i], tab[i + 1], atoi(tab[i + 2]), tab[i + 3]);
    }
}
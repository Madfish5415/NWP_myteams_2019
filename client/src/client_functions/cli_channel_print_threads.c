/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_channel_print_threads.c
*/

#include <stdlib.h>

#include "logging_client.h"
#include "utils.h"

void cli_channel_print_threads(char **tab)
{
    if (!tab)
        return;
    for (int i = 1; tab[i] != NULL; i += 5) {
        client_channel_print_threads(
            tab[i], tab[i + 1], atoi(tab[i + 2]), tab[i + 3], tab[i + 4]);
    }
}
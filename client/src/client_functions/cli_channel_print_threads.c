/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_channel_print_threads.c
*/

#include "logging_client.h"
#include "utils.h"

void cli_channel_print_threads(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    for (; tab[i] != NULL; i++);
    for (int j = 1; j < i; j += 5) {
        client_channel_print_threads(
            tab[i], tab[i + 1], strptime(tab[i + 2]), tab[i + 3], tab[i + 4]);
    }
}
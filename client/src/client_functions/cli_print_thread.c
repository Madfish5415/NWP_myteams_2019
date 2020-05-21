/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cli_print_thread.c
*/

#include "logging_client.h"
#include "utils.h"

void cli_print_thread(char **tab)
{
    if (!tab)
        return;
    client_print_thread(tab[1], tab[2], strptime(tab[3]), tab[4], tab[5]);
}
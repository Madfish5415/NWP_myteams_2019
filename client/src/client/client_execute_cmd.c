/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_execute_cmd.c
*/

#include <string.h>

#include "client.h"
#include "utils.h"

void client_execute_cmd(client_t *client)
{
    char **tab = NULL;

    if (!client->reader)
        return;
    tab = split(client->reader, "\r\n");
    if (!tab)
        return;
    for (int i = 0; MESSAGES_LOG[i].code != NULL; i++) {
        if (strncmp(tab[0], MESSAGES_LOG[i].code, 3) == 0) {
            MESSAGES_LOG[i].ptr(tab);
            FD_SET(client->sock, &client->worker[WRITE_SET]);
        }
    }
}
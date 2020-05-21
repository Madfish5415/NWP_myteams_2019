/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_clean.c
*/

#include "client.h"
#include <unistd.h>

void client_clean(client_t *client)
{
    if (client->reader) {
        free(client->reader);
    }
    close(client->sock);
    free(client);
}
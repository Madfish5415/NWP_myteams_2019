/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_init.c
*/

#include <string.h>

#include "socket.h"
#include "client.h"

int client_init(client_t *client, int port)
{
    client->sock = socket_creation();
    if (client->sock == -1) {
        return FAILURE;
    }
    client->serv_addr.sin_family = AF_INET;
    client->serv_addr.sin_port = htons(port);
    memset(client->reader, 0, sizeof(client->reader));
    memset(client->printer, 0, sizeof(client->printer));
    return SUCCESS;
}
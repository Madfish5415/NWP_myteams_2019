/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_disconnect.c
*/

#include <unistd.h>

#include "server.h"

void client_disconnect(server_t *server, client_t *client)
{
    close(client->socket);
    FD_CLR(client->socket, &server->master[READ_SET]);
    FD_CLR(client->socket, &server->master[WRITE_SET]);
    FD_CLR(client->socket, &server->master[EXCEPT_SET]);
    server_remove_client(server, server_get_client_index(server, client));
}
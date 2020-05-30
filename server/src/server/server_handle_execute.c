/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_handle_execute.c
*/

#include "server.h"

void server_handle_execute(server_t *server)
{
    if (!server)
        return;
    if (!server->clients)
        return;
    for (int i = 0; server->clients[i] != NULL; i++) {
        if (server->clients[i]->read_queue->buffer_length == 0)
            continue;
        client_execute(server, server->clients[i]);
        if (catch(server->exception))
            return;
    }
}
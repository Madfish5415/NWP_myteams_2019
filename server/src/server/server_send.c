/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_send.c
*/

#include <string.h>

#include "server.h"

void server_send_response(
    server_t *server, client_t *client, const char *response, bool separate)
{
    buffer_write_string(&client->write_queue, response);
    if (separate == true)
        buffer_write_string(&client->write_queue, "\r\n");
    if (catch_and_print(client->write_queue.exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
            "server_send_response (server/server_send.c)",
            "Can't write response");
        return;
    }
    FD_SET(client->socket, &server->master[WRITE_SET]);
}

void server_broadcast(server_t *server, const char *response, bool separate)
{
    if (!server->clients)
        return;
    for (int i = 0; server->clients[i] != NULL; i++)
        server_send_response(server, server->clients[i], response, separate);
}

void server_send_to_uuid(
    server_t *server, const char *uuid, const char *response, bool separate)
{
    if (!server->clients)
        return;
    for (int i = 0; server->clients[i] != NULL; i++) {
        if (strncmp(uuid, server->clients[i]->user, UUID_SIZE) == 0) {
            server_send_response(
                server, server->clients[i], response, separate);
            return;
        }
    }
}

void server_send_event(
    server_t *server, client_t *client, const char *response, bool separate)
{
    if (!server->clients)
        return;
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i] != client)
            server_send_response(
                server, server->clients[i], response, separate);
}
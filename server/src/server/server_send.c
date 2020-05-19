/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_send.c
*/

#include "server.h"

void server_send_response(
    server_t* server, client_t* client, const char* response)
{
    buffer_write_string(&client->write_queue, response);
    if (catch_and_print(client->write_queue.exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
            "server_send_response (server/server_send.c)",
            "Can't write response");
        return;
    }
    FD_SET(client->socket, &server->master[WRITE_SET]);
}
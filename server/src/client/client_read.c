/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_read.c
*/

#include <unistd.h>

#include "server.h"

void client_read(server_t *server, client_t *client)
{
    int read_value = 0;
    char buffer[BUFFER_SIZE];

    if ((read_value = read(client->socket, buffer, BUFFER_SIZE)) < 0) {
        server->exception = new_exception(RUNTIME_ERROR,
            "client_read (client_read.c)", "Can't read on the client fd");
        return;
    }
    if (read_value == 0) {
        client_disconnect(server, client);
    } else {
        buffer_write_string(client->read_queue, buffer);
        if (catch_and_print(client->read_queue->exception)) {
            server->exception = new_exception(RUNTIME_ERROR,
                "client_read (client_read.c)", "Can't write string");
            return;
        }
    }
}
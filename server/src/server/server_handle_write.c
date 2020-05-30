/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_handle_write.c
*/

#include "server.h"

static void handle_write(server_t *server, int fd)
{
    client_t *client = NULL;

    if (!FD_ISSET(fd, &server->worker[WRITE_SET]))
        return;
    if (fd != server->socket) {
        client = server_get_client(server, fd);
        if (!client)
            return;
        if (catch(server->exception))
            return;
        client_write(server, client);
        if (catch(server->exception))
            return;
    }
}

void server_handle_write(server_t *server)
{
    for (int fd = 0; fd < FD_SETSIZE; fd++) {
        handle_write(server, fd);
        if (catch(server->exception))
            return;
    }
}
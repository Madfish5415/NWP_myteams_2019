/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_init.c
*/

#include "exception.h"
#include "server.h"

static void init_socket(server_t *server)
{
    int opt = 1;

    if ((server->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        server->exception = new_exception(RUNTIME_ERROR,
            "init_socket (server/server_init.c)", "Can't create socket");
        return;
    }
    if (setsockopt(server->socket, SOL_SOCKET, (SO_REUSEADDR | SO_REUSEPORT),
            &opt, sizeof(opt)) < 0) {
        server->exception = new_exception(RUNTIME_ERROR,
            "init_socket (server/server_init.c)", "Can't set option on socket");
        return;
    }
}

static void bind_socket(server_t *server)
{
    if (bind(server->socket, (struct sockaddr *)&server->address,
            server->address_length) < 0) {
        server->exception = new_exception(
            RUNTIME_ERROR, "bind_socket (server/server_init.c)", "Bind error");
    }
}

static void listen_socket(server_t *server)
{
    if (listen(server->socket, MAX_CLIENT_QUEUE) < 0) {
        server->exception = new_exception(RUNTIME_ERROR,
            "listen_socket (server/server_init.c)", "Listen error");
    }
}

static void init_master_fd_set(server_t *server)
{
    FD_ZERO(&server->master[READ_SET]);
    FD_ZERO(&server->master[WRITE_SET]);
    FD_ZERO(&server->master[EXCEPT_SET]);
    FD_SET(server->socket, &server->master[READ_SET]);
    FD_SET(server->socket, &server->master[WRITE_SET]);
    FD_SET(server->socket, &server->master[EXCEPT_SET]);
}

void server_init(server_t *server)
{
    init_socket(server);
    if (catch(server->exception))
        return;
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(server->port);
    server->address_length = sizeof(server->address);
    bind_socket(server);
    if (catch(server->exception))
        return;
    listen_socket(server);
    if (catch(server->exception))
        return;
    init_master_fd_set(server);
}
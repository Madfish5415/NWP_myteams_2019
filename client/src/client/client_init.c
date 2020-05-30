/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_init.c
*/

#include <string.h>

#include "client.h"
#include "socket.h"

static void init_master_fd_set(client_t *client)
{
    FD_ZERO(&client->master[READ_SET]);
    FD_ZERO(&client->master[WRITE_SET]);
    FD_ZERO(&client->master[EXCEPT_SET]);
    FD_SET(client->sock, &client->master[READ_SET]);
    FD_SET(client->sock, &client->master[EXCEPT_SET]);
    FD_SET(0, &client->master[READ_SET]);
}

exception_t client_init(client_t *client, int port)
{
    exception_t exception = {NO_ERROR};

    client->sock = socket_creation();
    if (client->sock == -1) {
        return (new_exception(RUNTIME_ERROR,
            "client_init (client/client_init.c)",
            "Socket creation error."));
    }
    client->timeout.tv_usec = 10000;
    client->serv_addr.sin_family = AF_INET;
    client->serv_addr.sin_port = htons(port);
    client->reader = NULL;
    memset(client->printer, 0, sizeof(client->printer));
    init_master_fd_set(client);
    return (exception);
}
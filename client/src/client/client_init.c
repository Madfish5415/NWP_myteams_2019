/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_init.c
*/

#include <string.h>

#include "client.h"
#include "socket.h"

exception_t client_init(client_t *client, int port)
{
    exception_t exception = {NO_ERROR};

    client->sock = socket_creation();
    if (client->sock == -1) {
        return (new_exception(RUNTIME_ERROR,
            "client_init (client/client_init.c)",
            "Socket creation error."));
    }
    client->serv_addr.sin_family = AF_INET;
    client->serv_addr.sin_port = htons(port);
    memset(client->reader, 0, sizeof(client->reader));
    memset(client->printer, 0, sizeof(client->printer));
    return (exception);
}
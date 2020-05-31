/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_connect.c
*/

#include <string.h>

#include "buffer.h"
#include "client.h"
#include "server.h"

static void client_accept(server_t *server, client_t *client)
{
    if ((client->socket =
                accept(server->socket, (struct sockaddr *)&client->address,
                    (socklen_t *)&client->address_length)) < 0) {
        server->exception = new_exception(RUNTIME_ERROR,
            "client_accept (client/client_connect.c)",
            "Can't accept connection");
    }
}

static void client_init(server_t *server, client_t *client)
{
    memset(client->user, '\0', sizeof(client->user));
    client->read_queue = buffer_create();
    client->write_queue = buffer_create();
    client->address = server->address;
    client->address_length = server->address_length;
    client->use_type = NONE;
    memset(client->use_uuid, '\0', sizeof(client->use_uuid));
}

void client_connect(server_t *server)
{
    client_t *client = NULL;

    if ((client = malloc(sizeof(client_t))) == NULL) {
        server->exception =
            new_exception(BAD_ALLOC, "client_connect (client_connect.c)",
                "Can't allocate memory for client_t");
        return;
    }
    client_init(server, client);
    if (catch(server->exception))
        return;
    client_accept(server, client);
    if (catch(server->exception))
        return;
    server_add_client(server, client);
    if (catch(server->exception))
        return;
    FD_SET(client->socket, &server->master[READ_SET]);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_add.c
*/

#include "server.h"

static void server_alloc(server_t *server, client_t *client)
{
    bool first_one = (server->clients == NULL) ? true : false;

    if ((server->clients = realloc(server->clients,
    sizeof(client_t *) * (server_get_client_nbr(server) + 2))) == NULL) {
        server->exception =
            new_exception(BAD_ALLOC, "server_add_client (server/server_add.c)",
                "Can't realloc 'client_t *'");
        return;
    }
    if (first_one == true) {
        server->clients[0] = NULL;
        server->clients[1] = NULL;
    } else {
        server->clients[server_get_client_nbr(server) + 1] = NULL;
    }
    server->clients[server_get_client_nbr(server)] = client;
}

void server_add_client(server_t *server, client_t *client)
{
    server_alloc(server, client);
    if (catch (server->exception))
        return;
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_add.c
*/

#include <string.h>

#include "server.h"

static void server_alloc(server_t *server, client_t *client)
{
    bool first_one = (server->clients == NULL) ? true : false;
    int idx = 0;

    if (first_one) {
        server->clients = malloc(sizeof(client_t *) * 2);
        if (!server->clients) return;
        memset(server->clients, 0, sizeof(client_t *) * 2);
        server->clients[0] = client;
        server->clients[1] = NULL;
    } else {
        idx = server_get_client_nbr(server);
        server->clients =
            realloc(server->clients, sizeof(client_t *) * (idx + 2));
        if (!server->clients) return;
        memset(&server->clients[idx], 0, sizeof(client_t *) * 2);
        server->clients[idx] = client;
        server->clients[idx + 1] = NULL;
    }
}

void server_add_client(server_t *server, client_t *client)
{
    server_alloc(server, client);
    if (catch (server->exception))
        return;
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_remove.c
*/

#include "server.h"

void server_remove_client(server_t *server, int client_index)
{
    client_t *tmp = NULL;
    int last_client_index = server_get_client_nbr(server) - 1;

    if (client_index == -1) {
        server->exception = new_exception(OUT_OF_RANGE,
            "server_remove_client (server/server_remove.c)",
            "Index is out of range");
        return;
    }
    tmp = server->clients[last_client_index];
    server->clients[last_client_index] = server->clients[client_index];
    server->clients[client_index] = tmp;
    free(server->clients[last_client_index]);
    server->clients =
        realloc(server->clients, sizeof(client_t *) * (last_client_index + 1));
    if (!server->clients) return;
    server->clients[last_client_index] = NULL;
}

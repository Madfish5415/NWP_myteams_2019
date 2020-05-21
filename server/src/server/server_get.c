/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_get.c
*/

#include "server.h"

client_t *server_get_client(server_t *server, int fd)
{
    if (!server->clients)
        return (NULL);
    for (int i = 0; server->clients[i]; i++)
        if (server->clients[i]->socket == fd)
            return server->clients[i];
    return (NULL);
}

int server_get_client_nbr(server_t *server)
{
    int i = 0;

    if (!server->clients)
        return (0);
    for (; server->clients[i]; i++);
    return (i);
}

int server_get_client_index(server_t *server, client_t *client)
{
    if (!server->clients)
        return (-1);
    for (int i = 0; server->clients[i]; i++) {
        if (server->clients[i] == client)
            return (i);
    }
    return (-1);
}
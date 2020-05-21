/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_authorize.c
*/

#include <string.h>

#include "server.h"

static bool is_connected(client_t *client)
{
    if (!client)
        return (false);
    return (client->user[0] != '\0');
}

bool user_get_authorize(server_t *server, client_t *client, char **cmds)
{
    bool is_authorize = false;

    for (int i = 0; AUTHORIZE_LIST[i] != NULL; i++) {
        if (strcmp(AUTHORIZE_LIST[i], cmds[0]) == 0) {
            is_authorize = true;
            break;
        }
    }
    is_authorize = (is_connected(client)) ? true : is_authorize;
    if (!is_authorize)
        server_send_response(server, client, "530\r\n"); // TODO: Set response
    return is_authorize;
}
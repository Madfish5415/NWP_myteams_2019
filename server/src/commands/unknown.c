/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** unknown.c
*/

#include "server.h"

void cmd_unknown(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds))
        return;

    server_send_response(server, client, RESPONSE_505, false);
}
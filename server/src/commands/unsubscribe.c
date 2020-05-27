/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** unsubscribe.c
*/

#include "server.h"
#include "xml.h"

void cmd_unsubscribe(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds)) return;

    if (!cmds[1]) {
        server_send_response(server, client, RESPONSE_502, true);
        return;
    }
    if (!is_subscribe(server->xml_tree, cmds[1], client->user)) {
        server_send_response(server, client, RESPONSE_505, false);
        return;
    }
    subscribe_del(server->xml_tree, cmds[1], client->user);
    server_send_response(server, client, RESPONSE_251, false);
    server_send_response(server, client, client->user, true);
    server_send_response(server, client, cmds[1], true);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** unsubscribe.c
*/

#include "server.h"
#include "xml.h"
#include "logging_server.h"

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
    server_event_user_leave_a_team(cmds[1], client->user);
    for (int i = 0; server->clients[i]; i++)
        if (is_subscribe(server->xml_tree, cmds[1], server->clients[i]->user)) {
            server_send_response(
                server, server->clients[i], RESPONSE_251, false);
            server_send_response(
                server, server->clients[i], client->user, true);
            server_send_response(server, server->clients[i], cmds[1], true);
        }
}
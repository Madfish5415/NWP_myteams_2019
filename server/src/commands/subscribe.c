/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe.c
*/

#include "server.h"
#include "logging_server.h"

static void subscribe_to_team(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr subscribe = subscribe_create(client->user);
    subscribe_add(subscribe, server->xml_tree, cmds[1]);
    server_event_user_join_a_team(cmds[1], client->user);
    for (int i = 0; server->clients[i]; i++)
        if (is_subscribe(server->xml_tree, cmds[1], server->clients[i]->user)) {
            server_send_response(
                server, server->clients[i], RESPONSE_250, false);
            server_send_response(
                server, server->clients[i], client->user, true);
            server_send_response(server, server->clients[i], cmds[1], true);
        }
}

void cmd_subscribe(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr team = NULL;

    if (!user_get_authorize(server, client, cmds)) return;
    if (cmds[1] == NULL) {
        server_send_response(server, client, RESPONSE_502, true);
        return;
    }
    team = team_get(server->xml_tree, cmds[1]);
    if (!team) {
        server_send_response(server, client, RESPONSE_502, false);
        server_send_response(server, client, cmds[1], true);
        return;
    }
    if (is_subscribe(server->xml_tree, cmds[1], client->user)) {
        server_send_response(server, client, RESPONSE_506, true);
        return;
    }
    subscribe_to_team(server, client, cmds);
}
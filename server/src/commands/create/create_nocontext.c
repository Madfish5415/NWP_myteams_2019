/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_nocontext.c
*/

#include "server.h"

void create_nocontext(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr team = NULL;

    if (!cmds[1]) return;
    if (!cmds[2]) return;
    team = team_create(cmds[1], cmds[2], client->user);
    if (!team) return;
    team_add(team, server->xml_tree);
    server_send_response(server, client, RESPONSE_246, false);
    server_send_response(
        server, client, (char *)xml_node_get_content(team->children), true);
    server_send_response(server, client, cmds[1], true);
    server_send_response(server, client, cmds[2], true);
    server_broadcast(server, RESPONSE_234, false);
    server_broadcast(
        server, (char *)xml_node_get_content(team->children), true);
    server_broadcast(server, cmds[1], true);
    server_broadcast(server, cmds[2], true);

}

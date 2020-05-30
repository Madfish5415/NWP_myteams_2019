/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_nocontext.c
*/

#include <string.h>

#include "server.h"

static bool already_exist(server_t *server, const char *name)
{
    xml_node_ptr teams = server->xml_tree->children->children->next;

    if (!teams) return false;
    for (xml_node_ptr team = teams->children; team; team = team->next) {
        if (strcmp(xml_node_get_content(team->children->next), name) == 0)
            return true;
    }
    return false;
}

void create_nocontext(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr team = NULL;

    if (!cmds[1] || !cmds[2]) return;
    if (already_exist(server, cmds[1])) {
        server_send_response(server, client, RESPONSE_506, false);
        return;
    }
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

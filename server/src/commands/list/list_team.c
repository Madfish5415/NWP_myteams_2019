/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_team.c
*/

#include "server.h"

void list_team(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr team = team_get(server->xml_tree, client->use_uuid);

    (void) cmds;
    if (!team)
        return;
    for (xml_node_ptr channel =
        team->children->next->next->next->next->next->last;
        channel; channel = channel->prev) {
        server_send_response(server, client, RESPONSE_252, false);
        server_send_response(server, client,
            (char *)node_get_content(channel->children), true);
        server_send_response(server, client,
            (char *)node_get_content(channel->children->next), true);
        server_send_response(server, client,
            (char *)node_get_content(channel->children->next->next), true);
    }
}
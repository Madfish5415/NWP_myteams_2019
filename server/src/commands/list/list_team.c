/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_team.c
*/

#include "server.h"

void list_team(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr team = team_get(server->xml_tree, client->use_uuid);

    if (!team)
        return;
    server_send_response(server, client, RESPONSE_252, false);
    for (xmlNodePtr channel =
             team->children->next->next->next->next->next->children;
         channel; channel = channel->next) {
        server_send_response(
            server, client, (char *)xmlNodeGetContent(channel->children), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(channel->children->next), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(channel->children->next->next), true);
    }
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_team.c
*/

#include "server.h"

void info_team(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr team = team_get(server->xml_tree, client->use_uuid);

    (void) cmds;
    if (!team)
        return;
    server_send_response(server, client, RESPONSE_243, false);
    server_send_response(
        server, client, (char *)xmlNodeGetContent(team->children), true);
    server_send_response(
        server, client, (char *)xmlNodeGetContent(team->children->next), true);
    server_send_response(server, client,
        (char *)xmlNodeGetContent(team->children->next->next), true);
}
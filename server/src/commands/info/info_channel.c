/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_channel.c
*/

#include "server.h"

void info_channel(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr channel = channel_get(server->xml_tree, client->use_uuid);

    (void)cmds;
    if (!channel)
        return;
    server_send_response(server, client, RESPONSE_244, false);
    server_send_response(
        server, client, (char *)xmlNodeGetContent(channel->children), true);
    server_send_response(server, client,
        (char *)xmlNodeGetContent(channel->children->next), true);
    server_send_response(server, client,
        (char *)xmlNodeGetContent(channel->children->next->next), true);
}
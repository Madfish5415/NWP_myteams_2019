/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_channel.c
*/

#include "server.h"

void info_channel(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr channel = channel_get(server->xml_tree, client->use_uuid);

    (void)cmds;
    if (!channel)
        return;
    server_send_response(server, client, RESPONSE_244, false);
    server_send_response(
        server, client, (char *)node_get_content(channel->children), true);
    server_send_response(server, client,
        (char *)node_get_content(channel->children->next), true);
    server_send_response(server, client,
        (char *)node_get_content(channel->children->next->next), true);
}
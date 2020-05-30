/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_team.c
*/

#include "server.h"

static void send_to_others(
    server_t *server, client_t *client, char **cmds, xml_node_ptr channel)
{
    for (int i = 0; server->clients[i]; i++)
        if (is_subscribe(
            server->xml_tree, client->use_uuid, server->clients[i]->user)) {
            server_send_response(server, server->clients[i],
                RESPONSE_235, false);
            server_send_response(server, server->clients[i],
                (char *)xml_node_get_content(channel->children), true);
            server_send_response(server, server->clients[i], cmds[1], true);
            server_send_response(server, server->clients[i], cmds[2], true);
        }
}

static void send_to_client(
    server_t *server, client_t *client, char **cmds, xml_node_ptr channel)
{
    server_send_response(server, client, RESPONSE_247, false);
    server_send_response(
        server, client, (char *)xml_node_get_content(channel->children), true);
    server_send_response(server, client, cmds[1], true);
    server_send_response(server, client, cmds[2], true);
}

void create_team(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr channel = NULL;

    if (!is_subscribe(server->xml_tree, client->use_uuid, client->user)) {
        server_send_response(server, client, RESPONSE_505, false);
        return;
    }
    if (!cmds[1])
        return;
    if (!cmds[2])
        return;
    channel = channel_create(cmds[1], cmds[2], client->user, client->use_uuid);
    if (!channel)
        return;
    channel_add(channel, server->xml_tree, client->use_uuid);
    send_to_client(server, client, cmds, channel);
    send_to_others(server, client, cmds, channel);
}

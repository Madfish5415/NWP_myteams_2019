/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_channel.c
*/

#include "server.h"

static void send_to_others(
    server_t *server, client_t *client, char **cmds, xmlNodePtr thread)
{
    xmlNodePtr channel = channel_get(server->xml_tree, client->user);

    for (int i = 0; server->clients[i]; i++)
        if (is_subscribe(server->xml_tree, (char *)xmlNodeGetContent(
            channel->parent->prev->prev->prev->prev->prev),
            server->clients[i]->user)) {
            server_send_response(server, server->clients[i], RESPONSE_236,
                false);
            server_send_response(server, server->clients[i],
                (char *)xmlNodeGetContent(thread->children), true);
            server_send_response(server, server->clients[i], client->user,
                true);
            server_send_response(server, server->clients[i],
                (char *)xmlNodeGetContent(thread->children->next->next->next),
                true);
            server_send_response(server, server->clients[i], cmds[1], true);
            server_send_response(server, server->clients[i], cmds[2], true);
        }
}

static void send_to_client(
    server_t *server, client_t *client, char **cmds, xmlNodePtr thread)
{
    server_send_response(server, client, RESPONSE_236, false);
    server_send_response(
        server, client, (char *)xmlNodeGetContent(thread->children), true);
    server_send_response(server, client, client->user, true);
    server_send_response(server, client,
        (char *)xmlNodeGetContent(thread->children->next->next->next), true);
    server_send_response(server, client, cmds[1], true);
    server_send_response(server, client, cmds[2], true);
}

void create_channel(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr thread = NULL;
    xmlNodePtr channel = channel_get(server->xml_tree, client->use_uuid);

    if (!is_subscribe(server->xml_tree,
        xmlNodeGetContent(channel->parent->parent->children), client->user)) {
        server_send_response(server, client, RESPONSE_505, false);
        return;
    }
    if (!cmds[1])
        return;
    if (!cmds[2])
        return;
    thread = thread_create(cmds[1], cmds[2], client->user, client->use_uuid);
    if (!thread)
        return;
    thread_add(thread, server->xml_tree, client->use_uuid);
    send_to_client(server, client, cmds, thread);
    send_to_others(server, client, cmds, thread);
}

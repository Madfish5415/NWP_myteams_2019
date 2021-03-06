/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_channel.c
*/

#include <string.h>

#include "server.h"
#include "xml.h"

static bool already_exist(server_t *server, client_t *client, const char *name)
{
    xml_node_ptr threads = get_threads_channel(
        channel_get(server->xml_tree, client->use_uuid));

    if (!threads) return false;
    for (xml_node_ptr thread = threads->children; thread;
        thread = thread->next) {
        if (strcmp(node_get_content(thread->children->next), name) == 0)
            return true;
    }
    return false;
}

static void send_to_others(
    server_t *server, client_t *client, char **cmds, xml_node_ptr thread)
{
    xml_node_ptr channel = channel_get(server->xml_tree, client->use_uuid);

    if (!channel) return;
    for (int i = 0; server->clients[i]; i++)
        if (is_subscribe(server->xml_tree, (char *)node_get_content(
                    channel->parent->prev->prev->prev->prev->prev),
            server->clients[i]->user)) {
            server_send_response(server, server->clients[i], RESPONSE_236,
                false);
            server_send_response(server, server->clients[i],
                (char *)node_get_content(thread->children), true);
            server_send_response(server, server->clients[i], client->user,
                true);
            server_send_response(server, server->clients[i],
                (char *)node_get_content(
                    thread->children->next->next->next),
                true);
            server_send_response(server, server->clients[i], cmds[1], true);
            server_send_response(server, server->clients[i], cmds[2], true);
        }
}

static void send_to_client(
    server_t *server, client_t *client, char **cmds, xml_node_ptr thread)
{
    server_send_response(server, client, RESPONSE_248, false);
    server_send_response(
        server, client, (char *)node_get_content(thread->children), true);
    server_send_response(server, client, client->user, true);
    server_send_response(server, client,
        (char *)node_get_content(thread->children->next->next->next), true);
    server_send_response(server, client, cmds[1], true);
    server_send_response(server, client, cmds[2], true);
}

void create_channel(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr thread = NULL;
    xml_node_ptr channel = channel_get(server->xml_tree, client->use_uuid);

    if (!is_subscribe(server->xml_tree,
        node_get_content(channel->parent->parent->children),
        client->user)) {
        server_send_response(server, client, RESPONSE_505, false);
        return;
    }
    if (!cmds[1] || !cmds[2]) return;
    if (already_exist(server, client, cmds[1])) {
        server_send_response(server, client, RESPONSE_506, false);
        return;
    }
    thread = thread_create(cmds[1], cmds[2], client->user, client->use_uuid);
    if (!thread) return;
    thread_add(thread, server->xml_tree, client->use_uuid);
    send_to_client(server, client, cmds, thread);
    send_to_others(server, client, cmds, thread);
}

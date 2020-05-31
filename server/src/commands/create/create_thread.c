/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_thread.c
*/

#include "server.h"

static void send_to_others(
    server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr thread = thread_get(server->xml_tree, client->use_uuid);

    for (int i = 0; server->clients[i]; i++)
        if (is_subscribe(server->xml_tree,
            (char *)node_get_content(
            thread->parent->parent->parent->prev->prev->prev->prev->prev),
            server->clients[i]->user)) {
            server_send_response(
                server, server->clients[i], RESPONSE_233, false);
            server_send_response(server, server->clients[i],
                (char *)node_get_content(thread->parent->parent->parent
                ->prev->prev->prev->prev->prev), true);
            server_send_response(server, server->clients[i],
                (char *)node_get_content(thread->children), true);
            server_send_response(
                server, server->clients[i], client->user, true);
            server_send_response(server, server->clients[i], cmds[1], true);
        }
}

static void send_to_client(
    server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr thread = thread_get(server->xml_tree, client->use_uuid);

    server_send_response(server, client, RESPONSE_249, false);
    server_send_response(server, client,
        (char *)node_get_content(thread->children), true);
    server_send_response(server, client, client->user, true);
    server_send_response(server, client,
        (char *)node_get_content(thread->children->next->next->next), true);
    server_send_response(server, client, cmds[1], true);
}

void create_thread(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr reply = NULL;
    xml_node_ptr thread = thread_get(server->xml_tree, client->use_uuid);

    if (!is_subscribe(server->xml_tree,
            node_get_content(
                thread->parent->parent->parent->parent->children),
        client->user)) {
        server_send_response(server, client, RESPONSE_505, false);
        return;
    }
    if (!cmds[1])
        return;
    reply = message_thread_create(cmds[1], client->user, client->use_uuid);
    if (!reply)
        return;
    message_add(reply, server->xml_tree, client->use_uuid);
    send_to_client(server, client, cmds);
    send_to_others(server, client, cmds);
}

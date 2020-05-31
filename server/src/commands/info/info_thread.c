/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_thread.c
*/

#include "server.h"

void info_thread(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr thread = thread_get(server->xml_tree, client->use_uuid);

    (void)cmds;
    if (!thread)
        return;
    server_send_response(server, client, RESPONSE_245, false);
    server_send_response(
        server, client, (char *)node_get_content(thread->children), true);
    server_send_response(server, client,
        (char *)node_get_content(thread->children->next->next->next->next),
        true);
    server_send_response(server, client,
        (char *)node_get_content(thread->children->next->next->next), true);
    server_send_response(server, client,
        (char *)node_get_content(thread->children->next), true);
    server_send_response(server, client,
        (char *)node_get_content(thread->children->next->next), true);
}
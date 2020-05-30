/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_thread.c
*/

#include "server.h"

void list_thread(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr thread = thread_get(server->xml_tree, client->use_uuid);

    (void) cmds;
    if (!thread)
        return;
    for (xml_node_ptr message =
        thread->children->next->next->next->next->next->last;
        message; message = message->prev) {
        server_send_response(server, client, RESPONSE_254, false);
        server_send_response(server, client, client->use_uuid, true);
        server_send_response(server, client,
            (char *)xml_node_get_content(message->children->next->next), true);
        server_send_response(server, client,
            (char *)xml_node_get_content(message->children->next), true);
        server_send_response(server, client,
            (char *)xml_node_get_content(message->children), true);
    }
}
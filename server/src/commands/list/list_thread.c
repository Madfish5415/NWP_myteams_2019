/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_thread.c
*/

#include "server.h"

void list_thread(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr thread = thread_get(server->xml_tree, client->use_uuid);

    (void) cmds;
    if (!thread)
        return;
    server_send_response(server, client, RESPONSE_254, false);
    for (xmlNodePtr message =
             thread->children->next->next->next->next->next->children;
         message; message = message->next) {
        server_send_response(server, client, client->use_uuid, true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(message->children->next->next), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(message->children->next), true);
        server_send_response(
            server, client, (char *)xmlNodeGetContent(message->children), true);
    }
}
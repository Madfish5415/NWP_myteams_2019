/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_channel.c
*/

#include "server.h"

void list_channel(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr channel = channel_get(server->xml_tree, client->use_uuid);

    (void) cmds;
    if (!channel) return;
    for (xmlNodePtr thread =
        channel->children->next->next->next->next->next->last;
        thread; thread = thread->prev) {
        server_send_response(server, client, RESPONSE_253, false);
        server_send_response(
            server, client, (char *)xmlNodeGetContent(thread->children), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(thread->children->next->next->next->next),
            true);
        server_send_response(server, client, (char *)
            xmlNodeGetContent(thread->children->next->next->next), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(thread->children->next), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(thread->children->next->next), true);
    }
}
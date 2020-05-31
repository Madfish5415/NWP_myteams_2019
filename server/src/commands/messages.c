/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages.c
*/

#include "server.h"

static void send_all_messages(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr discussion =
        discussion_get(server->xml_tree, client->user, cmds[1]);

    if (!discussion) {
        return;
    }

    for (xml_node_ptr message = discussion->children->next->next->last;
        message; message = message->prev) {
        server_send_response(server, client, RESPONSE_255, false);
        server_send_response(server, client,
            (char *)node_get_content(message->children), true);
        server_send_response(server, client,
            (char *)node_get_content(message->children->next), true);
        server_send_response(server, client,
            (char *)node_get_content(message->children->next->next), true);
    }
}

void cmd_messages(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds))
        return;

    if (cmds[1] == NULL) {
        server_send_response(server, client, RESPONSE_501, false);
        server_send_response(
            server, client, "00000000-0000-0000-0000-000000000000", true);
        return;
    }
    if (!user_get_by_uuid(server->xml_tree, cmds[1])) {
        server_send_response(server, client, RESPONSE_501, false);
        server_send_response(server, client, cmds[1], true);
        return;
    }
    send_all_messages(server, client, cmds);
}
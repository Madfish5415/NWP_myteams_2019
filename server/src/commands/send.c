/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send.c
*/

#include <string.h>

#include "server.h"

static void send_discussion(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr discussion =
        message_discussion_create(client->user, cmds[1], cmds[2]);
    discussion_add_message(server->xml_tree, client->user, cmds[1], discussion);
    server_send_to_uuid(server, cmds[1], RESPONSE_232, false);
    server_send_to_uuid(server, cmds[1], client->user, true);
    server_send_to_uuid(server, cmds[1], cmds[2], true);
}

void cmd_send(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds)) return;
    if (cmds[1] == NULL) {
        server_send_response(server, client, RESPONSE_501, true);
        return;
    }
    if (cmds[2] == NULL || strncmp(client->user, cmds[1], UUID_SIZE) == 0) {
        server_send_response(server, client, RESPONSE_506, false);
        return;
    }
    if (!user_get_by_uuid(server->xml_tree, cmds[1])) {
        server_send_response(server, client, RESPONSE_501, false);
        server_send_response(server, client, cmds[1], true);
        return;
    }
    send_discussion(server, client, cmds);
}
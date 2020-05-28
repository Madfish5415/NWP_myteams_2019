/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.c
*/

#include <string.h>

#include "server.h"

static void print_user(server_t *server, client_t *client, xmlNodePtr user)
{
    server_send_response(server, client, RESPONSE_242, false);
    server_send_response(
        server, client, (char *)xmlNodeGetContent(user->children), true);
    server_send_response(
        server, client, (char *)xmlNodeGetContent(user->children->next), true);
    server_send_response(server, client,
        ((strcmp(
        (char *)xmlNodeGetContent(user->children->next->next->next->next),
        "false") == 0) ? "0" : "1"), true);
}

void cmd_user(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr user = NULL;

    if (!user_get_authorize(server, client, cmds))
        return;
    if (cmds[1] == NULL) {
        server_send_response(server, client, RESPONSE_501, true);
        return;
    }
    user = user_get_by_uuid(server->xml_tree, cmds[1]);
    if (!user) {
        server_send_response(server, client, RESPONSE_501, false);
        server_send_response(server, client, cmds[1], true);
    } else {
        print_user(server, client, user);
    }
}

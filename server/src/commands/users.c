/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users.c
*/

#include <string.h>

#include "server.h"

void cmd_users(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr root = NULL;

    if (!user_get_authorize(server, client, cmds))
        return;
    root = xmlDocGetRootElement(server->xml_tree);
    if (!root || !root->children ||
        strcmp((char *)root->children->name, "users") != 0)
        return;
    for (xmlNodePtr user = root->children->children; user; user = user->next) {
        server_send_response(server, client, RESPONSE_240, false);
        server_send_response(
            server, client, (char *)xmlNodeGetContent(user->children), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(user->children->next), true);
        server_send_response(server, client,
            ((strcmp((char *)xmlNodeGetContent(
            user->children->next->next->next->next), "false") == 0) ?
            "0" : "1"), true);
    }
}
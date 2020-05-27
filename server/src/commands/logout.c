/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout.c
*/

#include <string.h>

#include "logging_server.h"
#include "server.h"

void cmd_logout(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr user = NULL;

    if (!user_get_authorize(server, client, cmds)) return;

    user = user_get_by_uuid(server->xml_tree, client->user);

    server_broadcast(server, RESPONSE_231, false);
    server_broadcast(server, (char *)xmlNodeGetContent(user->children), true);
    server_broadcast(server,
        (char *)xmlNodeGetContent(user->children->next),true);
    server_event_user_logged_out((char *)xmlNodeGetContent(user->children));
    for (int i = 0; i < UUID_SIZE; i++) {
        client->user[i] = '\0';
        client->use_uuid[i] = '\0';
    }
    client->use_type = NONE;
    xmlNodeSetContent(user->children->next->next->next->next, BAD_CAST "false");
}
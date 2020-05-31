/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout.c
*/

#include <string.h>

#include "logging_server.h"
#include "server.h"

static bool not_already_connected(server_t *server, xml_node_ptr user)
{
    if (!server->clients) return false;
    for (int i = 0; server->clients[i]; i++) {
        if (strncmp(server->clients[i]->user,
                node_get_content(user->children), UUID_SIZE) == 0) {
            return true;
        }
    }
    return false;
}

void cmd_logout(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr user = NULL;

    if (!user_get_authorize(server, client, cmds)) return;
    user = user_get_by_uuid(server->xml_tree, client->user);
    server_broadcast(server, RESPONSE_231, false);
    server_broadcast(
        server, (char *)node_get_content(user->children), true);
    server_broadcast(server, (char *)node_get_content(user->children->next),
        true);
    server_event_user_logged_out((char *)node_get_content(user->children));
    for (int i = 0; i < UUID_SIZE; i++) {
        client->user[i] = '\0';
        client->use_uuid[i] = '\0';
    }
    client->use_type = NONE;
    if (!not_already_connected(server, user))
        node_set_content(
            user->children->next->next->next->next, BAD_CAST "false");
}
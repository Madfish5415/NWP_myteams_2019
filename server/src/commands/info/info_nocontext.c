/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info_nocontext.c
*/

#include "server.h"

void info_nocontext(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr user = user_get_by_uuid(server->xml_tree, client->user);

    (void) cmds;
    if (!user)
        return;
    server_send_response(server, client, RESPONSE_242, false);
    server_send_response(
        server, client, (char *)node_get_content(user->children), true);
    server_send_response(server, client,
        (char *)node_get_content(user->children->next), true);
    server_send_response(server, client, "1", true);
}
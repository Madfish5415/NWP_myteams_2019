/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_nocontext.c
*/

#include "server.h"

void list_nocontext(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr root = doc_get_root_element(server->xml_tree);
    xml_node_ptr team = root->children->next->last;

    (void) cmds;
    if (!team)
        return;
    for (; team; team = team->prev) {
        server_send_response(server, client, RESPONSE_241, false);
        server_send_response(
            server, client, (char *)node_get_content(team->children), true);
        server_send_response(server, client,
            (char *)node_get_content(team->children->next), true);
        server_send_response(server, client,
            (char *)node_get_content(team->children->next->next), true);
    }
}
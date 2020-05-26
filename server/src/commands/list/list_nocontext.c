/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_nocontext.c
*/

#include "server.h"

void list_nocontext(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr root = xmlDocGetRootElement(server->xml_tree);
    xmlNodePtr team = root->children->next->children;

    if (!team)
        return;
    server_send_response(server, client, RESPONSE_241, false);
    for (; team; team = team->next) {
        server_send_response(
            server, client, (char *)xmlNodeGetContent(team->children), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(team->children->next), true);
        server_send_response(server, client,
            (char *)xmlNodeGetContent(team->children->next->next), true);
    }
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribed.c
*/

#include <string.h>

#include "server.h"

void list_subscribed_team(server_t *server, client_t *client)
{
    xmlNodePtr root = xmlDocGetRootElement(server->xml_tree);
    xmlNodePtr team = root->children->next->children;

    server_send_response(server, client, RESPONSE_241, false);
    for (; team; team = team->next) {
        if (is_subscribe(server->xml_tree,
                (char *)xmlNodeGetContent(team->children), client->user)) {
            server_send_response(server, client,
                (char *)xmlNodeGetContent(team->children), true);
            server_send_response(server, client,
                (char *)xmlNodeGetContent(team->children->next), true);
            server_send_response(server, client,
                (char *)xmlNodeGetContent(team->children->next->next), true);
        }
    }
}

void list_subscribed_users(server_t *server, client_t *client)
{
    xmlNodePtr team = team_get(server->xml_tree, client->use_uuid);
    xmlNodePtr user = NULL;

    if (!team)
        return;
    server_send_response(server, client, RESPONSE_240, false);
    for (xmlNodePtr subscribe =
        team->children->next->next->next->next->next->next->children;
        subscribe; subscribe = subscribe->next) {
        user = user_get_by_uuid(
            server->xml_tree, (char *)xmlNodeGetContent(subscribe));
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

void cmd_subscribed(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds))
        return;
    if (client->use_uuid[0] == '\0') {
        list_subscribed_team(server, client);
    } else {
        list_subscribed_users(server, client);
    }
}
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
    xml_node_ptr root = doc_get_root_element(server->xml_tree);
    xml_node_ptr team = root->children->next->children;

    for (; team; team = team->next) {
        if (is_subscribe(server->xml_tree,
            (char *)node_get_content(team->children), client->user)) {
            server_send_response(server, client, RESPONSE_241, false);
            server_send_response(server, client,
                (char *)node_get_content(team->children), true);
            server_send_response(server, client,
                (char *)node_get_content(team->children->next), true);
            server_send_response(server, client,
                (char *)node_get_content(team->children->next->next), true);
        }
    }
}

void list_subscribed_users(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr team = team_get(server->xml_tree, cmds[1]);
    xml_node_ptr user = NULL;

    if (!team) return;
    for (xml_node_ptr subscribe =
        team->children->next->next->next->next->next->next->children;
        subscribe; subscribe = subscribe->next) {
        user = user_get_by_uuid(
            server->xml_tree, (char *)node_get_content(subscribe));
        server_send_response(server, client, RESPONSE_240, false);
        server_send_response(
            server, client, (char *)node_get_content(user->children), true);
        server_send_response(server, client,
            (char *)node_get_content(user->children->next), true);
        server_send_response(server, client,
            ((strcmp((char *)node_get_content(
            user->children->next->next->next->next), "false") == 0) ?
            "0" : "1"), true);
    }
}

void cmd_subscribed(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds))
        return;
    if (!cmds[1]) {
        list_subscribed_team(server, client);
    } else {
        if (!team_get(server->xml_tree, cmds[1])) {
            server_send_response(server, client, RESPONSE_502, false);
            server_send_response(server, client, cmds[1], true);
            return;
        }
        list_subscribed_users(server, client, cmds);
    }
}
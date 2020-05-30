/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login.c
*/

#include <string.h>

#include "logging_server.h"
#include "server.h"
#include "cmd.h"

static void succesfully_connected(
    server_t *server, client_t *client, xml_node_ptr user)
{
    for (int i = 0; i < UUID_SIZE &&
                    ((char *)xml_node_get_content(user->children))[i] != '\0'; i++)
        client->user[i] = ((char *)xml_node_get_content(user->children))[i];
    xml_node_set_content(
        user->children->next->next->next->next, BAD_CAST "true");
    server_broadcast(server, RESPONSE_230, false);
    server_broadcast(
        server, (char *)xml_node_get_content(user->children), true);
    server_broadcast(
        server, (char *)xml_node_get_content(user->children->next), true);
    server_event_user_logged_in((char *)xml_node_get_content(user->children));
}

static void create_new_user(server_t *server, xml_node_ptr *user, char **cmds)
{
    (*user) = user_create(cmds[1], "");
    user_add((*user), server->xml_tree);
    xml_node_set_content(
        (*user)->children->next->next->next->next, BAD_CAST "true");
}

void cmd_login(server_t *server, client_t *client, char **cmds)
{
    xml_node_ptr user = NULL;

    if (!user_get_authorize(server, client, cmds))
        return;
    if (cmds[1] == NULL) {
        server_send_response(server, client, RESPONSE_505, false);
        return;
    }
    user = user_get_by_name(server->xml_tree, cmds[1]);
    if (user == NULL) {
        create_new_user(server, &user, cmds);
    }
    if (client->user[0] != '\0') {
        server_send_response(server, client, RESPONSE_506, false);
        return;
    }
    succesfully_connected(server, client, user);
}
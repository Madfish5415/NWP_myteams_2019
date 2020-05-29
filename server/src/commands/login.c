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
    server_t *server, client_t *client, xmlNodePtr user)
{
    server_broadcast(server, RESPONSE_230, false);
    server_broadcast(server, (char *)xmlNodeGetContent(user->children), true);
    server_broadcast(
        server, (char *)xmlNodeGetContent(user->children->next), true);
    server_event_user_logged_in((char *)xmlNodeGetContent(user->children));
    for (int i = 0; i < UUID_SIZE &&
        ((char *)xmlNodeGetContent(user->children))[i] != '\0'; i++)
        client->user[i] = ((char *)xmlNodeGetContent(user->children))[i];
    xmlNodeSetContent(user->children->next->next->next->next, BAD_CAST "true");
}

static void create_new_user(server_t *server, xmlNodePtr *user, char **cmds)
{
    (*user) = user_create(cmds[1], "");
    user_add((*user), server->xml_tree);
    xmlNodeSetContent(
        (*user)->children->next->next->next->next, BAD_CAST "true");
}

void cmd_login(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr user = NULL;

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
    if (client->user[0] != '\0')
        cmd_logout(server, client, cmds);
    succesfully_connected(server, client, user);
}
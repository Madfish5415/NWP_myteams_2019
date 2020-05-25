/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use.c
*/

#include "server.h"

static void use_nocontext(client_t *client)
{
    for (int i = 0; i < UUID_SIZE; i++) {
        client->use_uuid[i] = '\0';
    }
    client->use_type = NONE;
}

static bool use_team(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr team = team_get(server->xml_tree, cmds[1]);

    if (!team) {
        server_send_response(server, client, RESPONSE_502, false);
        server_send_response(server, client, cmds[1], true);
        return true;
    }
    if (!subscriber_get(server->xml_tree, cmds[1], client->user)) {
        server_send_response(server, client, RESPONSE_505, false);
        return true;
    }
    for (int i = 0; i < UUID_SIZE && cmds[1][i] != '\0'; i++)
        client->use_uuid[i] = cmds[1][i];
    client->use_type = TEAM;
    return false;
}

static bool use_channel(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr channel = channel_get(server->xml_tree, cmds[2]);

    if (use_team(server, client, cmds))
        return true;
    if (!channel ||
        !channel_belongs_to_team(server->xml_tree, cmds[2], cmds[1])) {
        server_send_response(server, client, RESPONSE_503, false);
        server_send_response(server, client, cmds[2], true);
        return true;
    }
    for (int i = 0; i < UUID_SIZE && cmds[2][i] != '\0'; i++)
        client->use_uuid[i] = cmds[2][i];
    client->use_type = CHANNEL;
    return false;
}

static bool use_thread(server_t *server, client_t *client, char **cmds)
{
    xmlNodePtr thread = thread_get(server->xml_tree, cmds[3]);

    if (use_channel(server, client, cmds))
        return true;
    if (!thread ||
        !thread_belongs_to_channel(server->xml_tree, cmds[3], cmds[2])) {
        server_send_response(server, client, RESPONSE_504, false);
        server_send_response(server, client, cmds[3], true);
        return true;
    }
    for (int i = 0; i < UUID_SIZE && cmds[3][i] != '\0'; i++)
        client->use_uuid[i] = cmds[3][i];
    client->use_type = THREAD;
    return false;
}

void cmd_use(server_t *server, client_t *client, char **cmds)
{
    int len = 0;

    if (!user_get_authorize(server, client, cmds))
        return;

    for (; cmds[len] != NULL; len++);
    if (len == 1)
        use_nocontext(client);
    if (len == 2)
        use_team(server, client, cmds);
    if (len == 3)
        use_channel(server, client, cmds);
    if (len == 4)
        use_thread(server, client, cmds);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list.c
*/

#include "server.h"
#include "use.h"

void cmd_list(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds)) return;

    for (int i = 0; LIST_MAPPING[i].callback != NULL; i++) {
        if (LIST_MAPPING[i].use_type == client->use_type)
            return LIST_MAPPING[i].callback(server, client, cmds);
    }
}
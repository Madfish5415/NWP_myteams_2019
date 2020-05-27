/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info.c
*/

#include "server.h"
#include "use.h"

void cmd_info(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds)) return;

    for (int i = 0; INFO_MAPPING[i].callback != NULL; i++) {
        if (INFO_MAPPING[i].use_type == client->use_type)
            return INFO_MAPPING[i].callback(server, client, cmds);
    }
}
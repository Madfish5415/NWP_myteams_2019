/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create.c
*/

#include "server.h"
#include "use.h"

void cmd_create(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds)) return;

    for (int i = 0; CREATE_MAPPING[i].callback != NULL; i++) {
        if (CREATE_MAPPING[i].use_type == client->use_type)
            return CREATE_MAPPING[i].callback(server, client, cmds);
    }
}
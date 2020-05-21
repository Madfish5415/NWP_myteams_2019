/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info.c
*/

#include "server.h"

void cmd_info(server_t *server, client_t *client, char **cmds)
{
    if (!user_get_authorize(server, client, cmds)) return;
}
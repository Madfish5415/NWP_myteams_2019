/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_execute.c
*/

#include <string.h>

#include "cmd.h"
#include "server.h"
#include "utils.h"

static void execute(server_t *server, client_t *client, char **cmds)
{
    int i = 0;

    for (i = 0; CMD_MAPPING[i].callback != NULL; i++) {
        if (strcmp(CMD_MAPPING[i].cmd, cmds[0]) == 0) {
            CMD_MAPPING[i].callback(server, client, cmds);
            break;
        }
    }
    if (CMD_MAPPING[i].callback == NULL)
        cmd_unknown(server, client, cmds);
}

void client_execute(server_t *server, client_t *client)
{
    char *str = buffer_read_string(client->read_queue);
    char **cmds = NULL;

    if (catch_and_print(client->write_queue->exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
            "client_execute (client_execute.c)", "Can't read string");
        return;
    }
    cmds = split(str, "\r\n");
    if (cmds) {
        execute(server, client, cmds);
        for (int i = 0; cmds[i]; i++)
            free(cmds[i]);
        free(cmds);
    }
    if (str) free(str);
}
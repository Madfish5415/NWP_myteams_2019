/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_execute_cmd.c
*/

#include <string.h>

#include "client.h"
#include "utils.h"

static void execute(client_t *client, char **tab)
{
    char **tmp_tab = tab;

    if (tmp_tab == NULL || tmp_tab[0] == NULL)
        return;
    for (int i = 0; MESSAGES_LOG[i].code != NULL; i++) {
        if (strncmp(tmp_tab[0], MESSAGES_LOG[i].code, 3) == 0) {
            tmp_tab = MESSAGES_LOG[i].ptr(tmp_tab);
            return execute(client, tmp_tab);
        }
    }
}

void client_execute_cmd(client_t *client)
{
    char **tab = NULL;

    if (!client->reader)
        return;
    tab = split(client->reader, "\r\n");
    if (!tab)
        return;
    execute(client, tab);
    if (strncmp(client->printer, "/logout", 7) == 0)
        run(true);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    free(client->reader);
    client->reader = NULL;
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_handle_read.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "client.h"
#include "error.h"
#include "help.h"

void client_handle_read(client_t *client)
{
    exception_t exception = {NO_ERROR};

    for (int fd = 0; fd < FD_SETSIZE; fd++) {
        if (!FD_ISSET(fd, &client->worker[READ_SET]))
            continue;
        if (fd == 0) {
            memset(client->printer, 0, sizeof(client->printer));
            read(STDIN_FILENO, client->printer, sizeof(client->printer));
            if (!check_missing_quote(client->printer))
                memset(client->printer, 0, sizeof(client->printer));
            if (strncmp(client->printer, "/help", 5) == 0)
                printf("%s\n", HELP_STRING);
        }
        if (fd == client->sock) {
            exception = client_read_server(client);
            if (catch (exception)) return;
        }
    }
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_handle_write.c
*/

#include <string.h>

#include "client.h"

static exception_t send_message(client_t client)
{
    exception_t exception = {NO_ERROR};

    if (send(client.sock, format_string(client.printer), strlen(client.printer),
        0) < 0) {
        return new_exception(RUNTIME_ERROR,
            "client_loop (client/client_loop.c)", "Bad send execution.");
    }
    return exception;
}

void client_handle_write(client_t *client)
{
    exception_t exception = {NO_ERROR};

    for (int fd = 0; fd < FD_SETSIZE; fd++) {
        if (!FD_ISSET(fd, &client->worker[WRITE_SET]))
            continue;
        exception = send_message(*client);
        FD_CLR(fd, &client->worker[WRITE_SET]);
        if (catch (exception))
            return;
    }
}
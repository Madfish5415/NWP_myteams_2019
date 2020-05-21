/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_clean.c
*/

#include <string.h>
#include <unistd.h>

#include "client.h"

exception_t client_clean(client_t *client)
{
    exception_t exception = {NO_ERROR};
    if (client->reader) {
        free(client->reader);
    }
    if (send(client->sock, "/logout", strlen("/logout"), 0) < 0)
        return new_exception(RUNTIME_ERROR,
            "client_loop (client/client_loop.c)", "Bad send execution.");
    close(client->sock);
    return exception;
}
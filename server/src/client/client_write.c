/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_write.c
*/

#include <string.h>
#include <unistd.h>

#include "server.h"

void client_write(server_t *server, client_t *client)
{
    char *str = buffer_read_string(&client->write_queue);

    if (catch_and_print(client->write_queue.exception)) {
        server->exception = new_exception(RUNTIME_ERROR,
                                          "client_write (client_write.c)", "Can't read string");
        return;
    }
    write(client->socket, str, strlen(str));
    FD_CLR(client->socket, &server->master[WRITE_SET]);
    if (strcmp(str, RESPONSE_221) == 0)
        client_disconnect(server, client);
    free(str);
}
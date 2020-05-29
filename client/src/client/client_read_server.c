/*
** EPITECH PROJECT, 2020
** client
** File description:
** client_read_server.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "client.h"

exception_t client_read_server(client_t *client)
{
    char buffer_read[BUFFER_SIZE] = {0};
    ssize_t read_size = 0;
    int idx = 0;
    exception_t exception = {NO_ERROR};

    read_size = read(client->sock, buffer_read, READ_SIZE);
    while (read_size != -1 && read_size != 0) {
        client->reader = realloc(client->reader,
            sizeof(char) * (idx + read_size + 1));
        memset(&client->reader[idx], 0, read_size + 1);
        client->reader = strcat(client->reader, buffer_read);
        client->reader[strlen(client->reader)] = '\0';
        if (memchr(buffer_read, '\0', read_size)) break;
        memset(buffer_read, 0, sizeof(buffer_read));
        idx += read_size;
        if (read_size < READ_SIZE) break;
        read_size = read(client->sock, buffer_read, READ_SIZE);
    } if (read_size == 0)
        return client_clean(client);
    return exception;
}
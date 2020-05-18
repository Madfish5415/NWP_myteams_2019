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

void client_read_server(client_t *client)
{
    char buffer_read = 0;
    size_t len = 1;

    while (read(client->sock, &buffer_read, 1) != -1) {
        client->reader = realloc(client->reader, sizeof(char) * (len + 1));
        client->reader[len - 1] = buffer_read;
        buffer_read = 0;
        len++;
    }
    if (client->reader) client->reader[len - 1] = '\0';
}
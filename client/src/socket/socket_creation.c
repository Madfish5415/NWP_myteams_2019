/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** socket_creation.c
*/

#include <sys/socket.h>

#include "client.h"
#include "exception.h"

socket_t socket_creation()
{
    int sock = 0;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        catch_and_print(new_exception(RUNTIME_ERROR,
            "socket (src/socket/socket_creation.c)", "Socket creation error."));
        return FAILURE;
    }
    return sock;
}
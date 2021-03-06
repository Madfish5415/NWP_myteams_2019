/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** socket_connection.c
*/

#include <arpa/inet.h>

#include "client.h"
#include "exception.h"

exception_t socket_connection(char *ip, client_t client)
{
    exception_t exception = {NO_ERROR};

    if (inet_pton(AF_INET, ip, &client.serv_addr.sin_addr) <= 0) {
        return new_exception(RUNTIME_ERROR,
            "socket_connection (socket/socket_connection.c)",
            "Invalid address / Address not supported.");
    }
    if (connect(client.sock, (struct sockaddr *)&client.serv_addr,
            sizeof(client.serv_addr)) < 0) {
        return new_exception(RUNTIME_ERROR,
            "socket_connection (socket/socket_connection.c)",
            "Connection Failed.\n");
    }
    return (exception);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** socket_connection.c
*/

#include <arpa/inet.h>

#include "client.h"
#include "exception.h"

int socket_connection(char *ip, client_t client)
{
    if (inet_pton(AF_INET, ip, &client.serv_addr.sin_addr) <= 0) {
        catch_and_print(new_exception(RUNTIME_ERROR,
            "inet_pton (src/socket/socket_connection.c)",
            "Invalid address / Address not supported."));
        return FAILURE;
    }
    if (connect(client.sock, (struct sockaddr *)&client.serv_addr,
            sizeof(client.serv_addr)) < 0) {
        catch_and_print(new_exception(RUNTIME_ERROR,
            "connect (src/socket/socket_connection.c)",
            "Connection Failed.\n"));
        return -1;
    }
    return 0;
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client.h
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_H
#define NWP_MYTEAMS_2019_CLIENT_H

#include <arpa/inet.h>

#include "exception.h"
#include "def.h"

typedef struct client_s {
    socket_t sock;
    struct sockaddr_in serv_addr;
    char printer[MSG_MAX_SIZE];
    char *reader;
} client_t;

void client_loop(client_t client);
exception_t client_init(client_t *client, int port);
void client_read_server(client_t *client);
void client_clean(client_t *client);

#endif  // NWP_MYTEAMS_2019_CLIENT_H

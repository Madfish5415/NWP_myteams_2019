/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client.h
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_H
#define NWP_MYTEAMS_2019_CLIENT_H

#include <arpa/inet.h>

#include "def.h"

typedef struct client_s {
    socket_t sock;
    struct sockaddr_in serv_addr;
    char printer[MSG_MAX_SIZE];
    char reader[MSG_MAX_SIZE];
} client_t;

void client_loop(client_t client);
int client_init(client_t *client, int port);

#endif  // NWP_MYTEAMS_2019_CLIENT_H

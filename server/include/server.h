/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_H
#define NWP_MYTEAMS_2019_SERVER_H

#include <netinet/in.h>

#include "client.h"
#include "def.h"
#include "exception.h"

typedef struct server_s {
    uint16_t port;
    socket_t socket;
    struct sockaddr_in address;
    size_t address_length;
    client_t **clients;
    fd_set master[SET_NUMBER];
    fd_set worker[SET_NUMBER];
    struct timeval timeout;
    exception_t exception;
} server_t;

#endif  // NWP_MYTEAMS_2019_SERVER_H

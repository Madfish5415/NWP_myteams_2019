/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_H
#define NWP_MYTEAMS_2019_SERVER_H

#include <netinet/in.h>

#include "channel.h"
#include "client.h"
#include "def.h"
#include "exception.h"
#include "team.h"
#include "thread.h"
#include "user.h"

typedef struct server_s {
    uint16_t port;
    socket_t socket;
    struct sockaddr_in address;
    size_t address_length;
    client_t **clients;
    team_t **teams;
    channel_t **channels;
    thread_t **threads;
    user_t **users;
    fd_set master[SET_NUMBER];
    fd_set worker[SET_NUMBER];
    struct timeval timeout;
    exception_t exception;
} server_t;

#endif  // NWP_MYTEAMS_2019_SERVER_H

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_H
#define NWP_MYTEAMS_2019_SERVER_H

#include <libxml/tree.h>
#include <netinet/in.h>

#include "arguments.h"
#include "client.h"
#include "def.h"
#include "exception.h"

typedef struct server_s {
    uint16_t port;
    socket_t socket;
    struct sockaddr_in address;
    size_t address_length;
    client_t **clients;
    xmlDocPtr xml_tree;
    fd_set master[SET_NUMBER];
    fd_set worker[SET_NUMBER];
    struct timeval timeout;
    exception_t exception;
} server_t;

/*  server_create.c  */
exception_t server_create(server_t **server, args_t *arguments);

#endif  // NWP_MYTEAMS_2019_SERVER_H

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client.h
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_H
#define NWP_MYTEAMS_2019_CLIENT_H

#include <uuid/uuid.h>
#include <netinet/in.h>

#include "buffer.h"
#include "def.h"

enum use_type {
    NONE = 0,
    TEAM,
    CHANNEL,
    THREAD
};

typedef struct client_s {
    socket_t socket;
    struct sockaddr_in address;
    size_t address_length;
    char user[UUID_SIZE];
    buffer_t *read_queue;
    buffer_t *write_queue;
    int use_type;
    char use_uuid[UUID_SIZE];
} client_t;

typedef struct server_s server_t;  // Forward declare server_t

/*  client_connect.c  */
void client_connect(server_t *server);

/*  client_disconnect.c  */
void client_disconnect(server_t *server, client_t *client);

/*  client_execute.c  */
void client_execute(server_t *server, client_t *client);

/*  client_read.c  */
void client_read(server_t *server, client_t *client);

/*  client_write.c  */
void client_write(server_t *server, client_t *client);


#endif  // NWP_MYTEAMS_2019_CLIENT_H

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_H
#define NWP_MYTEAMS_2019_SERVER_H

#include <netinet/in.h>

#include "arguments.h"
#include "client.h"
#include "def.h"
#include "exception.h"
#include "libxml3.h"
#include "response.h"
#include "user.h"
#include "xml.h"

typedef struct server_s {
    uint16_t port;
    socket_t socket;
    struct sockaddr_in address;
    size_t address_length;
    client_t **clients;
    xml_doc_ptr xml_tree;
    fd_set master[SET_NUMBER];
    fd_set worker[SET_NUMBER];
    struct timeval timeout;
    exception_t exception;
} server_t;

/*  server_add.c  */
void server_add_client(server_t *server, client_t *client);

/*  server_create.c  */
exception_t server_create(server_t **server, args_t *arguments);

/*  server_delete.c  */
void server_delete(server_t **server);

/*  server_get.c  */
client_t *server_get_client(server_t *server, int fd);
int server_get_client_nbr(server_t *server);
int server_get_client_index(server_t *server, client_t *client);

/*  server_handle_execute.c  */
void server_handle_execute(server_t *server);

/*  server_handle_read.c  */
void server_handle_read(server_t *server);

/*  server_handle_execute.c  */
void server_handle_write(server_t *server);

/*  server_init.c  */
void server_init(server_t *server);

/*  server_remove.c  */
void server_remove_client(server_t *server, int client_index);

/*  server_run.c  */
void server_run(server_t *server);

/*  server_send.c  */
void server_send_response(
    server_t *server, client_t *client, const char *response, bool separate);
void server_broadcast(server_t *server, const char *response, bool separate);
void server_send_to_uuid(
    server_t *server, const char *uuid, const char *response, bool separate);
void server_send_event(
    server_t *server, client_t *client, const char *response, bool separate);

bool run_wrapper(bool stop); //TODO: Delete that

#endif // NWP_MYTEAMS_2019_SERVER_H

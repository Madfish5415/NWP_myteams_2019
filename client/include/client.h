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
#include "client_functions.h"

#define BUFFER_SIZE (1025)
#define READ_SIZE (1024)

typedef struct messages_log_s {
    const char *code;
    void (*ptr)(char **tab);
} messages_log_t;

static const messages_log_t MESSAGES_LOG[] = {
    {"230", &cli_event_loggedin},
    {"231", &cli_event_loggedout},
    {"232", &cli_event_private_message_received},
    {"233", &cli_event_thread_message_received},
    {"234", &cli_event_team_created},
    {"235", &cli_event_channel_created},
    {"236", &cli_event_thread_created},
    {"240", &cli_print_users},
    {"241", &cli_print_teams},
    {"242", &cli_print_user},
    {"243", &cli_print_team},
    {"244", &cli_print_channel},
    {"245", &cli_print_thread},
    {"246", &cli_print_team_created},
    {"247", &cli_print_channel_created},
    {"248", &cli_print_thread_created},
    {"249", &cli_print_reply_created},
    {"250", &cli_print_subscribed},
    {"251", &cli_print_unsubscribed},
    {"252", &cli_team_print_channels},
    {"253", &cli_channel_print_threads},
    {"254", &cli_thread_print_replies},
    {"255", &cli_private_message_print_messages},
    {"501", &cli_error_unknown_user},
    {"502", &cli_error_unknown_team},
    {"503", &cli_error_unknown_channel},
    {"504", &cli_error_unknown_thread},
    {"505", &cli_error_unauthorized},
    {"506", &cli_error_already_exist},
    {NULL, NULL}
};

typedef struct client_s {
    socket_t sock;
    struct sockaddr_in serv_addr;
    char printer[MSG_MAX_SIZE];
    char *reader;
} client_t;

exception_t client_loop(client_t client);
exception_t client_init(client_t *client, int port);
void client_read_server(client_t *client);
void client_clean(client_t *client);
void client_execute_cmd(client_t *client);

#endif  // NWP_MYTEAMS_2019_CLIENT_H

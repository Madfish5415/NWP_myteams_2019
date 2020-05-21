/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cmd.h
*/

#ifndef NWP_MYTEAMS_2019_CMD_H
#define NWP_MYTEAMS_2019_CMD_H

#include "server.h"

typedef struct cmd_s {
    char *cmd;
    void (*callback)(server_t *, client_t *, char **);
} cmd_t;

/*  create.c  */
void cmd_create(server_t *server, client_t *client, char **cmds);

/*  info.c  */
void cmd_info(server_t *server, client_t *client, char **cmds);

/*  list.c  */
void cmd_list(server_t *server, client_t *client, char **cmds);

/*  login.c  */
void cmd_login(server_t *server, client_t *client, char **cmds);

/*  logout.c  */
void cmd_logout(server_t *server, client_t *client, char **cmds);

/*  messages.c  */
void cmd_messages(server_t *server, client_t *client, char **cmds);

/*  send.c  */
void cmd_send(server_t *server, client_t *client, char **cmds);

/*  subscribe.c  */
void cmd_subscribe(server_t *server, client_t *client, char **cmds);

/*  subscribed.c  */
void cmd_subscribed(server_t *server, client_t *client, char **cmds);

/*  unknown.c  */
void cmd_unknown(server_t *server, client_t *client, char **cmds);

/*  unsubscribe.c  */
void cmd_unsubscribe(server_t *server, client_t *client, char **cmds);

/*  use.c  */
void cmd_use(server_t *server, client_t *client, char **cmds);

/*  user.c  */
void cmd_user(server_t *server, client_t *client, char **cmds);

/*  users.c  */
void cmd_users(server_t *server, client_t *client, char **cmds);

static const cmd_t CMD_MAPPING[] = {{"/create", &cmd_create},
    {"/info", &cmd_info}, {"/list", &cmd_list}, {"/login", &cmd_login},
    {"/logout", &cmd_logout}, {"/messages", &cmd_messages},
    {"/send", &cmd_send}, {"/subscribe", &cmd_subscribe},
    {"/subscribed", &cmd_subscribed}, {"/unsubscribe", &cmd_unsubscribe},
    {"/use", &cmd_use}, {"/user", &cmd_user}, {"/users", &cmd_users},
    {"UNKNOWN", NULL}};

#endif // NWP_MYTEAMS_2019_CMD_H

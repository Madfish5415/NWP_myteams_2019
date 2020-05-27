/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.h
*/

#ifndef NWP_MYTEAMS_2019_USER_H
#define NWP_MYTEAMS_2019_USER_H

static const char *const AUTHORIZE_LIST[] = {"/login", NULL};

typedef struct server_s server_t;
typedef struct client_s client_t;

/*  user_authorize.c  */
bool user_get_authorize(server_t *server, client_t *client, char **cmds);

#endif // NWP_MYTEAMS_2019_USER_H

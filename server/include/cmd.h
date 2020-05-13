/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** cmd.h
*/

#ifndef NWP_MYTEAMS_2019_CMD_H
#define NWP_MYTEAMS_2019_CMD_H

typedef struct cmd_s {
    char *cmd;
    void (*callback)(server_t *, uuid_t, char **);
} cmd_t;

#endif  // NWP_MYTEAMS_2019_CMD_H

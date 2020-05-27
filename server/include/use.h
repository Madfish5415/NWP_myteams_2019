/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use.h
*/

#ifndef NWP_MYTEAMS_2019_USE_H
#define NWP_MYTEAMS_2019_USE_H

#include "cmd.h"

typedef struct use_s {
    int use_type;
    void (*callback)(server_t *, client_t *, char **);
} use_t;

static const use_t CREATE_MAPPING[] = {
    {NONE, &create_nocontext},
    {TEAM, &create_team},
    {CHANNEL, &create_channel},
    {THREAD, &create_thread},
    {-1, NULL},
};

static const use_t INFO_MAPPING[] = {
    {NONE, &info_nocontext},
    {TEAM, &info_team},
    {CHANNEL, &info_channel},
    {THREAD, &info_thread},
    {-1, NULL},
};

static const use_t LIST_MAPPING[] = {
    {NONE, &list_nocontext},
    {TEAM, &list_team},
    {CHANNEL, &list_channel},
    {THREAD, &list_thread},
    {-1, NULL},
};

#endif // NWP_MYTEAMS_2019_USE_H

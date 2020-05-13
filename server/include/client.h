/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client.h
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_H
#define NWP_MYTEAMS_2019_CLIENT_H

#include <uuid/uuid.h>

enum use_type {
    NONE = 0,
    TEAM,
    CHANNEL,
    THREAD
};

typedef struct client_s {
    uuid_t user;
    char *read_queue; // TODO: Define this
    char *write_queue; // TODO: Define this
    int use_type;
    uuid_t use_uuid;
} client_t;

#endif  // NWP_MYTEAMS_2019_CLIENT_H

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel.h
*/

#ifndef NWP_MYTEAMS_2019_CHANNEL_H
#define NWP_MYTEAMS_2019_CHANNEL_H

#include <uuid/uuid.h>

#include "def.h"

typedef struct channel_s {
    uuid_t id;
    uuid_t team;
    uuid_t *threads;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    char creation_date[DATE_LENGTH];
} channel_t;

#endif  // NWP_MYTEAMS_2019_CHANNEL_H

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team.h
*/

#ifndef NWP_MYTEAMS_2019_TEAM_H
#define NWP_MYTEAMS_2019_TEAM_H

#include <uuid/uuid.h>

#include "def.h"

typedef struct team_s {
    uuid_t id;
    uuid_t *channels;
    uuid_t *subscribes;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    char creation_date[DATE_LENGTH];
} team_t;

#endif  // NWP_MYTEAMS_2019_TEAM_H

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** discussion.h
*/

#ifndef NWP_MYTEAMS_2019_DISCUSSION_H
#define NWP_MYTEAMS_2019_DISCUSSION_H

#include <uuid/uuid.h>

#include "def.h"
#include "message.h"

typedef struct discussion_s {
    uuid_t receiver;
    message_t *messages;
} discussion_t;

#endif  // NWP_MYTEAMS_2019_DISCUSSION_H

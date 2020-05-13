/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread.h
*/

#ifndef NWP_MYTEAMS_2019_THREAD_H
#define NWP_MYTEAMS_2019_THREAD_H

#include <uuid/uuid.h>

#include "def.h"
#include "message.h"

typedef struct thread_s {
    uuid_t id;
    uuid_t channel;
    char name[MAX_NAME_LENGTH];
    message_t body;
    message_t *comments;
} thread_t;

#endif  // NWP_MYTEAMS_2019_THREAD_H

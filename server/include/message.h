/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message.h
*/

#ifndef NWP_MYTEAMS_2019_MESSAGE_H
#define NWP_MYTEAMS_2019_MESSAGE_H

#include "def.h"

typedef struct message_s {
    char body[MAX_BODY_LENGTH];
    char date[DATE_LENGTH];
} message_t;

#endif  // NWP_MYTEAMS_2019_MESSAGE_H

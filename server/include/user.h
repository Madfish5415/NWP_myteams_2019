/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.h
*/

#ifndef NWP_MYTEAMS_2019_USER_H
#define NWP_MYTEAMS_2019_USER_H

#include <uuid/uuid.h>

#include "def.h"
#include "discussion.h"

typedef struct user_s {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    uuid_t id;
    bool connected;
    char creation_date[DATE_LENGTH];
    discussion_t **discussions;
} user_t;

#endif  // NWP_MYTEAMS_2019_USER_H

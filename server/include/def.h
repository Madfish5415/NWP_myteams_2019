/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** def.h
*/

#ifndef NWP_MYTEAMS_2019_DEF_H
#define NWP_MYTEAMS_2019_DEF_H

#define FAILURE (84)
#define SUCCESS (0)

typedef int socket_t;

#define MAX_CLIENT_QUEUE (10)

static const char *const XML_FILENAME = "server_data.xml";

#define SET_NUMBER (3)
#define READ_SET (0)
#define WRITE_SET (1)
#define EXCEPT_SET (2)

#define MAX_NAME_LENGTH (32)
#define MAX_DESCRIPTION_LENGTH (255)
#define MAX_BODY_LENGTH (512)

#define DATE_LENGTH (20)

#define USERNAME_SIZE (32)
#define PASSWORD_SIZE (32)

#define UUID_SIZE (37)
#define TIME_SIZE (64)

#endif  // NWP_MYTEAMS_2019_DEF_H

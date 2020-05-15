/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client.h
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_H
#define NWP_MYTEAMS_2019_CLIENT_H

#include <arpa/inet.h>
#define MSG_MAX_SIZE (1024)

typedef struct client_s {
  int sock;
  struct sockaddr_in serv_addr;
  char printer[MSG_MAX_SIZE];
  char reader[MSG_MAX_SIZE];
} client_t;

#endif // NWP_MYTEAMS_2019_CLIENT_H

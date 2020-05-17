/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** socket.h
*/

#ifndef NWP_MYTEAMS_2019_SOCKET_H
#define NWP_MYTEAMS_2019_SOCKET_H

#include "client.h"

socket_t socket_creation();
int socket_connection(char *ip, client_t client);

#endif  // NWP_MYTEAMS_2019_SOCKET_H

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** socket.c
*/

#include "../include/client.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>

int socket_creation()
{
  int sock = 0;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "Socket creation error.\n");
    return -1;
  }
  return sock;
}

int socket_connection(char *ip, client_t client)
{
  if (inet_pton(AF_INET, ip, &client.serv_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid address / Address not supported.\n");
    return -1;
  }
  if (connect(client.sock, (struct sockaddr *)&client.serv_addr,
              sizeof(client.serv_addr)) < 0) {
    fprintf(stderr, "Connection Failed.\n");
    return -1;
  }
  return 0;
}
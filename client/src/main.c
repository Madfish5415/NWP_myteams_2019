/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include "../include/client.h"
#include "../include/error.h"
#include "../include/socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int init_client(client_t *client, int port)
{
  client->sock = socket_creation();
  if (client->sock == -1) {
    return 84;
  }
  client->serv_addr.sin_family = AF_INET;
  client->serv_addr.sin_port = htons(port);
  return 0;
}

int main(int ac, char **av)
{
  char *printer;
  char reader[1024] = {0};
  size_t size = 0;
  client_t client;

  if (catch_error(ac, av) == 84) {
    return 84;
  }
  if (init_client(&client, atoi(av[2])) == 84) {
    return 84;
  }
  if (socket_connection(av[1], client) == -1) {
    return 84;
  }
  read(client.sock, reader, 1024);
  printf("%s\n", reader);
  while (1) {
    memset(reader, 0, sizeof(reader));
    getline(&printer, &size, stdin);
    send(client.sock, printer, strlen(printer), 0);
    read(client.sock, reader, 1024);
    printf("%s", reader);
  }
  return 0;
}
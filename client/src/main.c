/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include "../include/client.h"
#include "../include/error.h"
#include "../include/help.h"
#include "../include/socket.h"
#include <fcntl.h>
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
  memset(client->reader, 0, sizeof(client->reader));
  memset(client->printer, 0, sizeof(client->printer));
  return 0;
}

int client_loop(client_t client)
{
  while (1) {
    read(STDIN_FILENO, client.printer, sizeof(client.printer));
    if (strcmp(client.printer, "/help\n") == 0) {
      printf("%s\n", HELP_STRING);
    }
    else {
      send(client.sock, client.printer, strlen(client.printer), 0);
      usleep(2000);
      read(client.sock, client.reader, 1024);
      printf("%s", client.reader);
    }
    memset(client.reader, 0, sizeof(client.reader));
    memset(client.printer, 0, sizeof(client.printer));
  }
}

void set_non_blocking_read(client_t client)
{
  int flags;

  flags = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
  flags = fcntl(client.sock, F_GETFL, 0);
  fcntl(client.sock, F_SETFL, flags | O_NONBLOCK);
}

int main(int ac, char **av)
{
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
  set_non_blocking_read(client);
  client_loop(client);
  return 0;
}
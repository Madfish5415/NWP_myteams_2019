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
  return 0;
}

int client_loop(client_t client)
{
  char printer[1024] = {0};
  char reader[1024] = {0};

  while (1) {
    memset(reader, 0, sizeof(reader));
    memset(printer, 0, sizeof(printer));
    read(STDIN_FILENO, printer, sizeof(printer));
    if (strcmp(printer, "/help\n") == 0) {
      printf("%s\n", HELP_STRING);
    }
    else {
      send(client.sock, printer, strlen(printer), 0);
      usleep(2000);
      read(client.sock, reader, 1024);
      printf("%s", reader);
    }
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
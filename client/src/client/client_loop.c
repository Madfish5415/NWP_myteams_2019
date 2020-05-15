/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_loop.c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "help.h"

void client_loop(client_t client)
{
    while (1) {
        read(STDIN_FILENO, client.printer, sizeof(client.printer));
        if (strcmp(client.printer, "/help\n") == 0) {
            printf("%s\n", HELP_STRING);
        } else {
            send(client.sock, client.printer, strlen(client.printer), 0);
            usleep(2000);
            read(client.sock, client.reader, 1024);
            printf("%s", client.reader);
        }
        memset(client.reader, 0, sizeof(client.reader));
        memset(client.printer, 0, sizeof(client.printer));
    }
}
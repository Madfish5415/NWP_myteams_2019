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
#include <signal.h>

static bool run(bool stop, client_t client)
{
    static bool is_running = true;

    if (stop) {
        send(client.sock, "/logout\n", strlen("/logout\n"), 0);
        is_running = false;
    }
    return is_running;
}

static void signal_handler(int sig)
{
    (void) sig;

    run(true);
}

void client_loop(client_t client)
{
    signal(SIGINT, signal_handler);
    while (run(false, client)) {
        read(STDIN_FILENO, client.printer, sizeof(client.printer));
        if (strcmp(client.printer, "/help\n") == 0) {
            printf("%s\n", HELP_STRING);
        } else {
            send(client.sock, client.printer, strlen(client.printer), 0);
        }
        client_read_server(&client);
        if (client.reader) {
            printf("%s", client.reader);
            free(client.reader);
            client.reader = NULL;
        }
        memset(client.printer, 0, sizeof(client.printer));
    }
}
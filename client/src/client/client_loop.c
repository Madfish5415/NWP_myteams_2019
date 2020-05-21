/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_loop.c
*/

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "client.h"
#include "help.h"

static bool run(bool stop)
{
    static bool is_running = true;

    if (stop) {
        is_running = false;
    }
    return is_running;
}

static void signal_handler(int sig)
{
    (void)sig;

    run(true);
}

exception_t client_loop(client_t client)
{
    exception_t exception = {NO_ERROR};

    signal(SIGINT, signal_handler);
    while (run(false)) {
        read(STDIN_FILENO, client.printer, sizeof(client.printer));
        if (strncmp(client.printer, "/help", 5) == 0)
            printf("%s\n", HELP_STRING);
        else {
            if (send(client.sock, client.printer, strlen(client.printer), 0) <
                0)
                return new_exception(RUNTIME_ERROR,
                    "client_loop (client/client_loop.c)",
                    "Bad send execution.");
        }
        client_read_server(&client);
        client_execute_cmd(&client);
        memset(client.printer, 0, sizeof(client.printer));
    }
    client_clean(&client);
    return exception;
}
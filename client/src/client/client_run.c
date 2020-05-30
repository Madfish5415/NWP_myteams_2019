/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_loop.c
*/

#include <signal.h>

#include "client.h"
#include "help.h"

bool run(bool stop)
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

exception_t client_run(client_t client)
{
    exception_t exception = {NO_ERROR};

    signal(SIGINT, signal_handler);
    while (run(false)) {
        client.worker[READ_SET] = client.master[READ_SET];
        client.worker[WRITE_SET] = client.master[WRITE_SET];
        client.worker[EXCEPT_SET] = client.master[EXCEPT_SET];
        if (select(FD_SETSIZE, &client.worker[READ_SET],
            &client.worker[WRITE_SET], &client.worker[EXCEPT_SET],
            &client.timeout) < 0) {
            return exception;
        }
        client_handle_fd(&client);
    }
    exception = client_clean(&client);
    return exception;
}
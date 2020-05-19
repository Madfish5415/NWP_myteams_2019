/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_run.c
*/

#include <signal.h>
#include <stdlib.h>
#include <sys/socket.h>

#include "exception.h"
#include "server.h"

static bool run_wrapper(bool stop)
{
    static bool is_running = true;

    if (stop)
        is_running = false;
    return is_running;
}

static void server_handle_fd(server_t *server)
{
    server_handle_read(server);
    if (catch(server->exception))
        return;
    server_handle_execute(server);
    if (catch(server->exception))
        return;
    server_handle_write(server);
    if (catch(server->exception))
        return;
}

static void signal_handler(int sig)
{
    (void) sig;

    run_wrapper(true);
}

void server_run(server_t *server)
{
    signal(SIGINT, signal_handler);
    while (run_wrapper(false)) {
        server->worker[READ_SET] = server->master[READ_SET];
        server->worker[WRITE_SET] = server->master[WRITE_SET];
        server->worker[EXCEPT_SET] = server->master[EXCEPT_SET];
        if (select(FD_SETSIZE, &server->worker[READ_SET],
                &server->worker[WRITE_SET], &server->worker[EXCEPT_SET],
                &server->timeout) < 0) {
            server->exception =
                new_exception(RUNTIME_ERROR, "server", "Select failed");
            return;
        }
        server_handle_fd(server);
        if (catch(server->exception))
            return;
    }
}
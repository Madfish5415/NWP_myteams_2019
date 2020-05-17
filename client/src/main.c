/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <fcntl.h>
#include <unistd.h>

#include "arguments.h"
#include "client.h"
#include "exception.h"
#include "socket.h"

static void set_non_blocking_read(client_t client)
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
    args_t *arguments;

    if (catch_and_print(parser(ac, av, &arguments))) {
        return (FAILURE);
    }
    if (arguments->flags[HELP_FLAG] == true) {
        return (SUCCESS);
    }
    if (catch_and_print(client_init(&client, atoi(av[2])))) {
        return (FAILURE);
    }
    if (catch_and_print(socket_connection(av[1], client))) {
        return (FAILURE);
    }
    set_non_blocking_read(client);
    client_loop(client);
    return (SUCCESS);
}
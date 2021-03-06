/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include "arguments.h"
#include "client.h"
#include "exception.h"
#include "socket.h"

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
    if (catch_and_print(client_run(client)))
        return (FAILURE);
    return (SUCCESS);
}
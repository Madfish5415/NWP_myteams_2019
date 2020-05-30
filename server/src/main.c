/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include "arguments.h"
#include "help.h"
#include "server.h"

int main(int argc, char **argv)
{
    args_t *arguments;
    server_t *server;

    if (catch_and_print(parser(argc, argv, &arguments))) {
        return (FAILURE);
    }
    if (arguments->flags[HELP_FLAG] == true)
        return (SUCCESS);
    server_create(&server, arguments);
    if (catch_and_print(server->exception))
        return (FAILURE);
    server_init(server);
    if (catch_and_print(server->exception))
        return (FAILURE);
    server_run(server);
    if (catch_and_print(server->exception))
        return (FAILURE);
    server_delete(&server);
    free(arguments);
    return (SUCCESS);
}
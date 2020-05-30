/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** port.c
*/

#include "arguments.h"

static int count_args(int argc, char **argv)
{
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') count++;
    }
    return count;
}

static char *find_port(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-' && argv[i + 1] && argv[i + 1][0] != '-')
            return (argv[i + 1]);
    return (NULL);
}

static bool is_valid(const char *port)
{
    for (int i = 0; port[i] != '\0'; i++)
        if (port[i] < '0' || port[i] > '9') return false;
    return true;
}

exception_t fill_port(int argc, char **argv, args_t *arguments)
{
    int port = 0;
    char *port_arg = NULL;
    exception_t exception = {NO_ERROR};

    if (count_args(argc, argv) != 2)
        return (new_exception(INVALID_ARGUMENT, "fill_port (arguments/port.c)",
            "Invalid argument number"));
    if ((port_arg = find_port(argc, argv)) == NULL)
        return (new_exception(INVALID_ARGUMENT, "fill_port (arguments/port.c)",
            "Unable to find port"));
    if (!is_valid(port_arg))
        return (new_exception(INVALID_ARGUMENT, "fill_port (arguments/port.c)",
            "Port is not a number"));
    port = atoi(port_arg);
    if (port < 0 || port > 65535)
        return (new_exception(INVALID_ARGUMENT, "fill_port (arguments/port.c)",
            "Port number is invalid"));
    arguments->port = (uint16_t)port;
    return (exception);
}
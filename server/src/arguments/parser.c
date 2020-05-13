/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parser.c
*/

#include "arguments.h"
#include "help.h"

exception_t parser(int argc, char **argv, args_t **arguments)
{
    exception_t exception;
    args_t *new_arguments = malloc(sizeof(args_t));

    if (new_arguments == NULL)
        return (new_exception(BAD_ALLOC, "parser (arguments/parser.c)",
                              "Can't allocate memory for 'args_t'"));
    (*arguments) = new_arguments;
    init_flag(new_arguments);
    if ((exception = fill_flag(argc, argv, new_arguments)).code != NO_ERROR)
        return (exception);
    if (display_help(new_arguments)) return (exception);
    if ((exception = fill_port(argc, argv, new_arguments)).code != NO_ERROR)
        return (exception);
    return (exception);
}
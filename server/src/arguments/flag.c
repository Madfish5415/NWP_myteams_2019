/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** flag.c
*/

#include <string.h>

#include "arguments.h"

static const flag_match_t FLAG_MAPPING[] = {
    {"-h", HELP_FLAG},
    {"-help", HELP_FLAG},
    {"--help", HELP_FLAG},
    {"-v", VERBOSE_FLAG},
    {"-verbose", VERBOSE_FLAG},
    {"--verbose", VERBOSE_FLAG},
    {NULL, NULL_FLAG},
};

static exception_t find_flag(char *flag, args_t *arguments)
{
    exception_t exception = {NO_ERROR};

    for (int i = 0; FLAG_MAPPING[i].string != NULL; i++) {
        if (strcmp(FLAG_MAPPING[i].string, flag) == 0) {
            arguments->flags[FLAG_MAPPING[i].flag_id] = true;
            return (exception);
        }
    }
    exception = new_exception(
        INVALID_ARGUMENT, "find_flag (arguments/flag.c)", "A flag is invalid");
    return (exception);
}

exception_t fill_flag(int argc, char **argv, args_t *arguments)
{
    exception_t exception = {NO_ERROR};

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            exception = find_flag(argv[i], arguments);
        }
        if (catch(exception)) {
            return (exception);
        }
    }

    return (exception);
}

void init_flag(args_t *arguments)
{
    arguments->flags[HELP_FLAG] = false;
    arguments->flags[VERBOSE_FLAG] = false;
}
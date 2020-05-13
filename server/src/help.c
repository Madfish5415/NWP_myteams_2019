/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help.c
*/

#include <stdio.h>

#include "arguments.h"
#include "help.h"

bool display_help(args_t* arguments)
{
    if (arguments->flags[HELP_FLAG] == true) {
        printf("%s", HELP_MESSAGE);
        return (true);
    }
    return (false);
}
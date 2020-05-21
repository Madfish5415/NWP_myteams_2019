/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help.h
*/

#ifndef NWP_MYTEAMS_2019_HELP_H
#define NWP_MYTEAMS_2019_HELP_H

#include "arguments.h"

static const char *const HELP_MESSAGE =
    "USAGE ./myteams_server port \n\tport\tis the port number on which the "
    "server socket listens\n";

/*  help.c  */
bool display_help(args_t *arguments);

#endif  // NWP_MYTEAMS_2019_HELP_H

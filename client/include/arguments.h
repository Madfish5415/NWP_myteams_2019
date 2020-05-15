/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** arguments.h
*/

#ifndef NWP_MYTEAMS_2019_ARGUMENTS_H
#define NWP_MYTEAMS_2019_ARGUMENTS_H

#include <stdbool.h>
#include <stdint.h>

#include "exception.h"

#define MAX_FLAGS 2

enum flag_id_list { NULL_FLAG = -1, HELP_FLAG = 0, VERBOSE_FLAG };

typedef struct flag_match_s {
    const char *const string;
    int16_t flag_id;
} flag_match_t;

typedef struct args_s {
    uint16_t port;
    bool flags[MAX_FLAGS];
} args_t;

/*  flag.c  */
exception_t fill_flag(int argc, char **argv, args_t *arguments);
void init_flag(args_t *arguments);

/*  parser.c  */
exception_t parser(int argc, char **argv, args_t **arguments);

/*  port.c  */
exception_t fill_port(int argc, char **argv, args_t *arguments);

#endif  // NWP_MYTEAMS_2019_ARGUMENTS_H

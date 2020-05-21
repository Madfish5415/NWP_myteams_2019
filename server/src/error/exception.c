/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** exception.c
*/

#include "exception.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const code_match_t ERROR_CODE_MAPPING[] = {{NO_ERROR, NULL},
    {BAD_ALLOC, "BAD ALLOC"}, {BAD_TYPEID, "BAD TYPEID"},
    {BAD_EXCEPTION, "BAD EXCEPTION"}, {LOGIC_FAILURE, "LOGIC FAILURE"},
    {DOMAIN_ERROR, "DOMAIN_ERROR"}, {INVALID_ARGUMENT, "INVALID ARGUMENT"},
    {LENGTH_ERROR, "LENGTH ERROR"}, {OUT_OF_RANGE, "OUT OF RANGE"},
    {RUNTIME_ERROR, "RUNTIME ERROR"}, {OVERFLOW_ERROR, "OVERFLOW ERROR"},
    {RANGE_ERROR, "RANGE ERROR"}, {UNDERFLOW_ERROR, "UNDERFLOW ERROR"},
    {UNKNOWN_ERROR, "UNKNOWN ERROR"}, {-1, NULL}};

static const char *error_code_to_string(int16_t code)
{
    for (int i = 0; ERROR_CODE_MAPPING[i].nbr != -1; i++)
        if (ERROR_CODE_MAPPING[i].nbr == code)
            return (ERROR_CODE_MAPPING[i].str);
    return (NULL);
}

exception_t new_exception(int16_t code, const char *where, const char *what)
{
    exception_t exception;

    exception.code = code;
    exception.where = strdup(where);
    exception.what = strdup(what);

    return (exception);
}

bool catch(exception_t exception)
{
    if (exception.code == NO_ERROR)
        return (false);
    return (true);
}

void print_exception(exception_t exception)
{
    if (exception.code == NO_ERROR)
        return;

    fprintf(stderr, "An error has occurred (%s)\nwhere(): %s\nwhat(): %s\n",
        error_code_to_string(exception.code), exception.where, exception.what);
    free(exception.where);
    free(exception.what);
}

bool catch_and_print(exception_t exception)
{
    if (exception.code == NO_ERROR)
        return (false);

    print_exception(exception);
    return (true);
}
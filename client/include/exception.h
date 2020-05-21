/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** exception.h
*/

#ifndef NWP_MYTEAMS_2019_EXCEPTION_H
#define NWP_MYTEAMS_2019_EXCEPTION_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

enum error_type {
    NO_ERROR = 0,
    BAD_ALLOC,
    BAD_CAST,
    BAD_TYPEID,
    BAD_EXCEPTION,
    LOGIC_FAILURE,
    DOMAIN_ERROR,
    INVALID_ARGUMENT,
    LENGTH_ERROR,
    OUT_OF_RANGE,
    RUNTIME_ERROR,
    OVERFLOW_ERROR,
    RANGE_ERROR,
    UNDERFLOW_ERROR,
    UNKNOWN_ERROR
};

typedef struct code_match_s {
    const int16_t nbr;
    const char *const str;
} code_match_t;

typedef struct exception_s {
    int16_t code;
    char *what;
    char *where;
} exception_t;

exception_t new_exception(int16_t code, const char *where, const char *what);
bool catch (exception_t exception);
void print_exception(exception_t exception);
bool catch_and_print(exception_t exception);

#endif  // NWP_MYTEAMS_2019_EXCEPTION_H
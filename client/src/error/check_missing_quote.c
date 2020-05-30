/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** check_missing_quote.c
*/

#include <string.h>
#include <stdio.h>
#include <regex.h>

#include "exception.h"
#include "utils.h"

static bool valid_arg(const char *string)
{
    char *regex_str = "^\\/[a-z]+(\\s+\\\"[^\\\"]+\\\")+\n$";
    regex_t regex;
    size_t max_group = 2;
    regmatch_t group[max_group];

    if (regcomp(&regex, regex_str, REG_EXTENDED))
        return NULL;
    if (regexec(&regex, string, max_group, group, 0) == 0) {
        regfree(&regex);
        return true;
    }
    regfree(&regex);
    return false;
}

static bool valid_cmd(const char *string)
{
    char *regex_str = "^\\/[a-z]+\n$";
    regex_t regex;
    size_t max_group = 2;
    regmatch_t group[max_group];

    if (regcomp(&regex, regex_str, REG_EXTENDED))
        return NULL;
    if (regexec(&regex, string, max_group, group, 0) == 0) {
        regfree(&regex);
        return true;
    }
    regfree(&regex);
    return false;
}

bool check_missing_quote(const char *string)
{
    if (!valid_arg(string) && !valid_cmd(string)) {
        printf("Invalid argument.\n");
        return false;
    }
    return true;
}
/*
** EPITECH PROJECT, 2020
** libxml3
** File description:
** regex.c
*/

#include <regex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "libxml3.h"

static char *extractRegex(const char *string, regmatch_t match)
{
    char *res = NULL;

    if (string == NULL) return NULL;
    res = strndup(&string[match.rm_so], match.rm_eo - match.rm_so);
    return res;
}

static char *getFirstLine(const char *str)
{
    int len = 0;
    char *result;

    if (!str) return NULL;

    for (int i = 0; str[i] && str[i] != '\n'; i++, len++);
    result = strndup(str, len);
    return result;
}

char *getOpenBalise(char *string)
{
    char *regex_str = "^\\s*<([a-zA-Z0-9]+)>.*$";
    regex_t regex;
    size_t max_group = 2;
    regmatch_t group[max_group];
    char *res = NULL;
    char *new_str = NULL;

    if (regcomp(&regex, regex_str, REG_EXTENDED))
        return NULL;
    new_str = getFirstLine(string);
    if (regexec(&regex, new_str, max_group, group, 0) == 0) {
        res = extractRegex(new_str, group[1]);
    }
    free(new_str);
    regfree(&regex);
    return res;
}

char *getCloseBalise(char *string)
{
    char *regex_str = "^.*<\\/([a-zA-Z0-9]+)>\\s*$";
    regex_t regex;
    size_t max_group = 2;
    regmatch_t group[max_group];
    char *res = NULL;
    char *new_str = NULL;

    if (regcomp(&regex, regex_str, REG_EXTENDED))
        return NULL;
    new_str = getFirstLine(string);
    if (regexec(&regex, new_str, max_group, group, 0) == 0) {
        res = extractRegex(new_str, group[1]);
    }
    free(new_str);
    regfree(&regex);
    return res;
}

char *getBaliseContent(char *string)
{
    char *regex_str = "^\\s*<([a-zA-Z0-9]+)>(.*)<\\/\\1+>\\s*$";
    regex_t regex;
    size_t max_group = 3;
    regmatch_t group[max_group];
    char *res = NULL;
    char *new_str = NULL;

    if (regcomp(&regex, regex_str, REG_EXTENDED))
        return NULL;
    new_str = getFirstLine(string);
    if (regexec(&regex, new_str, max_group, group, 0) == 0) {
        res = extractRegex(new_str, group[2]);
    }
    free(new_str);
    regfree(&regex);
    return res;
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_format_string.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *find_string(char *string)
{
    static unsigned int idx = 0;
    static char *old_str = NULL;
    unsigned int size = 0;
    unsigned int i = 0;
    char *tmp = NULL;

    if (old_str == NULL || strcmp(old_str, string) != 0) {
        if (old_str) free(old_str);
        old_str = strdup(string);
        idx = 0;
    }
    for (; string[idx] && string[idx] != '\"'; idx++);
    idx++;
    for (size = idx; string[size] && string[size] != '\"'; size++);
    tmp = malloc(sizeof(char) * (size - idx + 1));
    for (i = 0; string[idx] && string[idx] != '\"'; idx++, i++)
        tmp[i] = string[idx];
    idx++;
    tmp[i] = '\0';
    return tmp;
}

static unsigned int get_args(char *string)
{
    unsigned long nb_quotes = 0;

    for (int i = 0; string[i]; i++)
        nb_quotes += (string[i] == '\"');
    nb_quotes = (nb_quotes / 2) + 1;
    return nb_quotes;
}

char *format_string(char *string)
{
    char *cmd = NULL;
    char *frmt = NULL;
    char *tmp = NULL;

    if (string[0] == 0) return NULL;
    tmp = strdup(string);
    cmd = strtok(tmp, " ");
    if (!cmd) return NULL;
    frmt = strdup(cmd);
    for (unsigned int i = 1; i < get_args(string); i++) {
        tmp = find_string(string);
        frmt =
            realloc(frmt, sizeof(char) * (strlen(frmt) + strlen(tmp) + 3));
        frmt = strcat(frmt, "\r\n");
        frmt = strcat(frmt, tmp);
    } if (cmd != tmp) free(tmp);
    free(cmd);
    frmt = realloc(frmt, sizeof(char) * (strlen(frmt) + 3));
    frmt = strcat(frmt, "\r\n");
    return frmt;
}
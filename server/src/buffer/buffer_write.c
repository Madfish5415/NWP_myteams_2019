/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** buffer_write.c
*/

#include <string.h>

#include "buffer.h"

static char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result == NULL)
        return NULL;
    memset(result, '\0', strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void buffer_write_string(buffer_t *buffer, const char *str)
{
    char *tmp = NULL;

    if (str == NULL)
        return;
    if (buffer->buffer == NULL) {
        buffer->buffer = strdup(str);
    } else {
        tmp = concat(buffer->buffer, str);
        free(buffer->buffer);
        buffer->buffer = tmp;
    }
    if (buffer->buffer)
        buffer->buffer_length = (int) strlen(buffer->buffer);
}
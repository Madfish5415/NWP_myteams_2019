/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** buffer_read.c
*/

#include <string.h>

#include "buffer.h"

char *buffer_read_string(buffer_t *buffer)
{
    char *result = strdup(buffer->buffer);

    free(buffer->buffer);
    buffer->buffer = NULL;
    buffer->buffer_length = 0;

    return result;
}
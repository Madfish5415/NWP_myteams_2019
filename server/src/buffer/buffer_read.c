/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** buffer_read.c
*/

#include <stdbool.h>
#include <stdlib.h>

#include "buffer.h"

static bool is_valid(buffer_t *buffer)
{
    if (!buffer) return false;
    if (buffer->buffer_length == 0) {
        buffer->exception = new_exception(
            RANGE_ERROR, "is_valid (buffer/buffer_read.c)", "Buffer is empty");
        return false;
    }
    if (buffer->read_index < 0 || buffer->read_index >= BUFFER_SIZE) {
        buffer->exception = new_exception(RANGE_ERROR,
            "is_valid (buffer/buffer_read.c)", "Invalid write index");
        return false;
    }
    if (buffer->buffer_length < 0 || buffer->buffer_length >= BUFFER_SIZE) {
        buffer->exception = new_exception(RANGE_ERROR,
            "is_valid (buffer/buffer_read.c)", "Invalid buffer length");
        return false;
    }
    return true;
}

char buffer_read_character(buffer_t *buffer)
{
    char c = '\0';

    if (!is_valid(buffer)) return c;

    c = buffer->buffer[buffer->read_index];

    buffer->buffer_length--;
    buffer->read_index++;
    buffer->read_index %= BUFFER_SIZE;
    return c;
}

char *buffer_read_string(buffer_t *buffer)
{
    char *str = NULL;
    int i = 0;

    if (!is_valid(buffer)) return str;
    if ((str = malloc(sizeof(char) * (buffer->buffer_length + 1))) == NULL) {
        buffer->exception = new_exception(BAD_ALLOC,
            "buffer_read_string (buffer/buffer_read.c)",
            "Can't allocate memory for 'char *'");
        return str;
    }
    for (i = 0; buffer->buffer_length != 0; i++) {
        str[i] = buffer_read_character(buffer);
        if (buffer->exception.code != NO_ERROR) {
            free(str);
            return NULL;
        }
    }
    str[i] = '\0';
    return str;
}
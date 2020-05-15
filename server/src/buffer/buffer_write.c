/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** buffer_write.c
*/

#include <stdbool.h>

#include "buffer.h"

static bool is_valid(buffer_t *buffer)
{
    if (!buffer) return false;
    if (buffer->buffer_length == BUFFER_SIZE) {
        buffer->exception = new_exception(RANGE_ERROR,
                                          "is_valid (buffer/buffer_write.c)", "Buffer is currently full");
        return false;
    }
    if (buffer->write_index < 0 || buffer->write_index >= BUFFER_SIZE) {
        buffer->exception = new_exception(RANGE_ERROR,
                                          "is_valid (buffer/buffer_write.c)", "Invalid write index");
        return false;
    }
    if (buffer->buffer_length < 0 || buffer->buffer_length >= BUFFER_SIZE) {
        buffer->exception = new_exception(RANGE_ERROR,
                                          "is_valid (buffer/buffer_write.c)", "Invalid buffer length");
        return false;
    }
    return true;
}

void buffer_write_character(buffer_t *buffer, const char c)
{
    if (!is_valid(buffer)) return;

    buffer->buffer[buffer->write_index] = c;

    buffer->write_index++;
    buffer->buffer_length++;
    buffer->write_index %= BUFFER_SIZE;
}

void buffer_write_string(buffer_t *buffer, const char *const str)
{
    if (!is_valid(buffer)) return;

    for (int i = 0; str && str[i] != '\0'; i++) {
        buffer_write_character(buffer, str[i]);
        if (buffer->exception.code != NO_ERROR) return;
    }
}
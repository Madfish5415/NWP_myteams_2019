/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** buffer_delete.c
*/

#include "buffer.h"

void buffer_delete(buffer_t *buffer)
{
    if (buffer->buffer) {
        free(buffer->buffer);
        buffer->buffer = NULL;
    }
    buffer->buffer_length = 0;
    catch_and_print(buffer->exception);
}

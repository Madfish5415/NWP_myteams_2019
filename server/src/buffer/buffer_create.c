/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** buffer_create.c
*/

#include "buffer.h"

buffer_t buffer_create(void)
{
    buffer_t buffer;

    buffer.buffer_length = 0;
    buffer.buffer = NULL;
    buffer.exception.code = NO_ERROR;
    return (buffer);
}
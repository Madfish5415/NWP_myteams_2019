/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** buffer.h
*/

#ifndef NWP_MYTEAMS_2019_BUFFER_H
#define NWP_MYTEAMS_2019_BUFFER_H

#include "exception.h"

#define BUFFER_SIZE 1024

typedef struct buffer_s {
    char buffer[BUFFER_SIZE];
    int buffer_length;
    int read_index;
    int write_index;
    exception_t exception;
} buffer_t;

/*  buffer_create.c  */
buffer_t buffer_create(void);

/*  buffer_read.c  */
char buffer_read_character(buffer_t *buffer);
char *buffer_read_string(buffer_t *buffer);

/*  buffer_write.c  */
void buffer_write_character(buffer_t *buffer, const char c);
void buffer_write_string(buffer_t *buffer, const char *const str);

#endif  // NWP_MYTEAMS_2019_BUFFER_H

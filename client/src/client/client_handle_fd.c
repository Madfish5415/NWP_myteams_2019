/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_handle_fd.c
*/

#include "client.h"

void client_handle_fd(client_t *client)
{
    client_handle_read(client);
    client_execute_cmd(client);
    client_handle_write(client);
}
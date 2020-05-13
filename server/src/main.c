/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <uuid/uuid.h>

#include "server.h"

int main(void)
{
    client_t client;

    uuid_clear(client.user);

    return (uuid_is_null(client.user));
}
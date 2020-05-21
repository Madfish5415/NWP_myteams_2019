/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_delete.c
*/

#include <libxml/tree.h>
#include <unistd.h>

#include "server.h"

void server_delete(server_t **server)
{
    close((*server)->socket);
    xmlSaveFormatFile(XML_FILENAME, (*server)->xml_tree, 1);
    free((*server));
}
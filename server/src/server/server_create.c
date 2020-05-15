/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_create.c
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "arguments.h"
#include "server.h"

static xmlDocPtr create_new_xml()
{
    xmlDocPtr xmlTree = xmlNewDoc(BAD_CAST "1.0");
    xmlNodePtr serverNode = xmlNewNode(NULL, BAD_CAST "server");
    xmlNodePtr usersNode = xmlNewNode(NULL, BAD_CAST "users");
    xmlNodePtr teamsNode = xmlNewNode(NULL, BAD_CAST "teams");
    xmlNodePtr discussionsNode = xmlNewNode(NULL, BAD_CAST "discussions");

    if (xmlTree == NULL) return (NULL);
    xmlDocSetRootElement(xmlTree, serverNode);
    xmlAddChild(serverNode, usersNode);
    xmlAddSibling(usersNode, teamsNode);
    xmlAddSibling(usersNode, discussionsNode);
    return (xmlTree);
}

static xmlDocPtr load_xml()
{
    xmlDocPtr xmlTree = xmlParseFile("server_data.xml");

    if (xmlTree == NULL) {
        xmlTree = create_new_xml();
    }
    return (xmlTree);
}

exception_t server_create(server_t **server, args_t *arguments)
{
    server_t *new_server = malloc(sizeof(server_t));

    if (new_server == NULL)
        return (
            new_exception(BAD_ALLOC, "server_create (server/server_create.c)",
                "Can't allocate memory for 'server_t'"));
    (*server) = new_server;
    if ((new_server->port = arguments->port) == 0)
        return (new_exception(INVALID_ARGUMENT,
            "server_create (server/server_create.c)", "Invalid port detected"));
    new_server->socket = -1;
    new_server->exception.code = NO_ERROR;
    new_server->address_length = sizeof(new_server->address);
    new_server->clients = NULL;
    if ((new_server->xmlTree = load_xml()) == NULL)
        return (new_exception(INVALID_ARGUMENT,
            "server_create (server/server_create.c)",
            "Can't load xml in memory"));
    new_server->timeout.tv_sec = 0;
    new_server->timeout.tv_usec = 10000;
    return (new_server->exception);
}
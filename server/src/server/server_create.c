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
    xmlDocPtr xml_tree = xmlNewDoc(BAD_CAST "1.0");
    xmlNodePtr serverNode = xmlNewNode(NULL, BAD_CAST "server");
    xmlNodePtr usersNode = xmlNewNode(NULL, BAD_CAST "users");
    xmlNodePtr teamsNode = xmlNewNode(NULL, BAD_CAST "teams");
    xmlNodePtr discussionsNode = xmlNewNode(NULL, BAD_CAST "discussions");

    if (xml_tree == NULL) return (NULL);
    xmlDocSetRootElement(xml_tree, serverNode);
    xmlAddChild(serverNode, usersNode);
    xmlAddSibling(usersNode, teamsNode);
    xmlAddSibling(usersNode, discussionsNode);
    return (xml_tree);
}

static xmlDocPtr load_xml()
{
    xmlDocPtr xml_tree = xmlParseFile("server_data.xml");

    if (xml_tree == NULL) {
        xml_tree = create_new_xml();
    }
    return (xml_tree);
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
    if ((new_server->xml_tree = load_xml()) == NULL)
        return (new_exception(INVALID_ARGUMENT,
            "server_create (server/server_create.c)",
            "Can't load xml in memory"));
    new_server->timeout.tv_sec = 0;
    new_server->timeout.tv_usec = 10000;
    return (new_server->exception);
}
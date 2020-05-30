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
#include "logging_server.h"
#include "server.h"

static xmlDocPtr create_new_xml(void)
{
    xmlDocPtr xml_tree = xmlNewDoc(BAD_CAST "1.0");
    xmlNodePtr serverNode = xmlNewNode(BAD_CAST "server");
    xmlNodePtr usersNode = xmlNewNode(BAD_CAST "users");
    xmlNodePtr teamsNode = xmlNewNode(BAD_CAST "teams");
    xmlNodePtr discussionsNode = xmlNewNode(BAD_CAST "discussions");

    if (xml_tree == NULL)
        return (NULL);
    xmlDocSetRootElement(xml_tree, serverNode);
    xmlAddChild(serverNode, usersNode);
    xmlAddSibling(usersNode, teamsNode);
    xmlAddSibling(usersNode, discussionsNode);
    return (xml_tree);
}

static xmlDocPtr load_xml(void)
{
    xmlDocPtr xml_tree = NULL;

    if (access(XML_FILENAME, R_OK) != -1) {
        xml_tree = xmlParseFile(XML_FILENAME);
    } else {
        if (xml_tree == NULL) {
            xml_tree = create_new_xml();
        }
    }
    return (xml_tree);
}

static void load_existing_users(server_t *server)
{
    xmlNodePtr root = xmlDocGetRootElement(server->xml_tree);

    if (!root || !root->children)
        return;
    for (xmlNodePtr user = root->children->children; user; user = user->next) {
        if (user->children && user->children->next)
            server_event_user_loaded((char *)xmlNodeGetContent(user->children),
                (char *)xmlNodeGetContent(user->children->next));
    }
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
    new_server->clients = NULL;
    if ((new_server->xml_tree = load_xml()) == NULL)
        return (new_exception(INVALID_ARGUMENT,
            "server_create (server/server_create.c)",
            "Can't load xml in memory"));
    load_existing_users((*server));
    new_server->timeout.tv_usec = 10000;
    return (new_server->exception);
}
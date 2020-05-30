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

static xml_doc_ptr create_new_xml(void)
{
    xml_doc_ptr xml_tree = xml_new_doc(BAD_CAST "1.0");
    xml_node_ptr serverNode = xml_new_node(BAD_CAST "server");
    xml_node_ptr usersNode = xml_new_node(BAD_CAST "users");
    xml_node_ptr teamsNode = xml_new_node(BAD_CAST "teams");
    xml_node_ptr discussionsNode = xml_new_node(BAD_CAST "discussions");

    if (xml_tree == NULL)
        return (NULL);
    xml_doc_set_root_element(xml_tree, serverNode);
    xml_add_child(serverNode, usersNode);
    xml_add_sibling(usersNode, teamsNode);
    xml_add_sibling(usersNode, discussionsNode);
    return (xml_tree);
}

static xml_doc_ptr load_xml(void)
{
    xml_doc_ptr xml_tree = NULL;

    if (access(XML_FILENAME, R_OK) != -1) {
        xml_tree = xml_parse_file(XML_FILENAME);
    } else {
        if (xml_tree == NULL) {
            xml_tree = create_new_xml();
        }
    }
    return (xml_tree);
}

static void load_existing_users(server_t *server)
{
    xml_node_ptr root = xml_doc_get_root_element(server->xml_tree);

    if (!root || !root->children)
        return;
    for (xml_node_ptr user = root->children->children; user;
        user = user->next) {
        if (user->children && user->children->next)
            server_event_user_loaded(
                (char *)xml_node_get_content(user->children),
                (char *)xml_node_get_content(user->children->next));
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
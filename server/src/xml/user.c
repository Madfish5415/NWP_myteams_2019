/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.c
*/

#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "exception.h"
#include "libxml3.h"
#include "logging_server.h"

xml_node_ptr user_create(const char *username, const char *passwd)
{
    xml_node_ptr user;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[TIME_SIZE];
    char uuid_str[UUID_SIZE];

    strftime(time_str, sizeof(time_str), "%d-%m-%y %H:%M:%S", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    user = xml_new_node(BAD_CAST "user");
    xml_new_text_child(user, BAD_CAST "uuid", BAD_CAST uuid_str);
    xml_new_text_child(user, BAD_CAST "username", BAD_CAST username);
    xml_new_text_child(user, BAD_CAST "password", BAD_CAST passwd);
    xml_new_text_child(user, BAD_CAST "date", BAD_CAST time_str);
    xml_new_text_child(user, BAD_CAST "connected", BAD_CAST "false");
    server_event_user_created(uuid_str, username);
    return user;
}

exception_t user_add(xml_node_ptr user, xml_doc_ptr xml_tree)
{
    xml_node_ptr root = xml_doc_get_root_element(xml_tree);
    exception_t exception = {NO_ERROR};

    if (!root || !root->children) {
        exception = new_exception(OUT_OF_RANGE, "user_add (xml/user.c)",
            "Root of the document not found");
        return exception;
    }
    if (strcmp((char *)root->children->name, "users") != 0) {
        exception = new_exception(OUT_OF_RANGE, "user_add (xml/user.c)",
            "The first category of the XML doc is not users");
        return exception;
    }
    xml_add_child(root->children, user);
    return exception;
}

xml_node_ptr user_get_by_name(xml_doc_ptr xml_tree, const char *username)
{
    xml_node_ptr root = xml_doc_get_root_element(xml_tree);

    if (!root || !root->children || !root->children->children)
        return NULL;
    for (xml_node_ptr user = root->children->children; user;
        user = user->next) {
        if (!user->children || !user->children->next)
            return NULL;
        if (strcmp((char *)xml_node_get_content(user->children->next),
                username) == 0)
            return user;
    }
    return NULL;
}

xml_node_ptr user_get_by_uuid(xml_doc_ptr xml_tree, const char *uuid)
{
    xml_node_ptr root = xml_doc_get_root_element(xml_tree);

    if (!root || !root->children || !root->children->children)
        return NULL;
    for (xml_node_ptr user = root->children->children; user;
        user = user->next) {
        if (!user->children || !user->children->next)
            return NULL;
        if (strcmp((char *)xml_node_get_content(user->children), uuid) == 0)
            return user;
    }
    return NULL;
}
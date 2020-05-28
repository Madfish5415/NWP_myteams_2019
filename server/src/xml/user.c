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

xmlNodePtr user_create(const char *username, const char *passwd)
{
    xmlNodePtr user;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[TIME_SIZE];
    char uuid_str[UUID_SIZE];

    strftime(time_str, sizeof(time_str), "%d-%m-%y %H:%M:%S", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    user = xmlNewNode(BAD_CAST "user");
    xmlNewTextChild(user, BAD_CAST "uuid", BAD_CAST uuid_str);
    xmlNewTextChild(user, BAD_CAST "username", BAD_CAST username);
    xmlNewTextChild(user, BAD_CAST "password", BAD_CAST passwd);
    xmlNewTextChild(user, BAD_CAST "date", BAD_CAST time_str);
    xmlNewTextChild(user, BAD_CAST "connected", BAD_CAST "false");
    server_event_user_created(uuid_str, username);
    return user;
}

exception_t user_add(xmlNodePtr user, xmlDocPtr xml_tree)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);
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
    xmlAddChild(root->children, user);
    return exception;
}

xmlNodePtr user_get_by_name(xmlDocPtr xml_tree, const char *username)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);

    if (!root || !root->children || !root->children->children)
        return NULL;
    for (xmlNodePtr user = root->children->children; user; user = user->next) {
        if (!user->children || !user->children->next)
            return NULL;
        if (strcmp((char *)xmlNodeGetContent(user->children->next),
                username) == 0)
            return user;
    }
    return NULL;
}

xmlNodePtr user_get_by_uuid(xmlDocPtr xml_tree, const char *uuid)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);

    if (!root || !root->children || !root->children->children)
        return NULL;
    for (xmlNodePtr user = root->children->children; user; user = user->next) {
        if (!user->children || !user->children->next)
            return NULL;
        if (strcmp((char *)xmlNodeGetContent(user->children), uuid) == 0)
            return user;
    }
    return NULL;
}
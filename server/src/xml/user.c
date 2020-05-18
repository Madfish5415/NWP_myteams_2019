/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.c
*/

#include <libxml/tree.h>
#include <time.h>
#include <uuid/uuid.h>
#include <string.h>
#include "logging_server.h"

xmlNodePtr user_create(const char *username, const char *passwd)
{
    xmlNodePtr user;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[64];
    char uuid_str[37];

    strftime(time_str, sizeof(time_str), "%c", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);

    user = xmlNewNode(NULL, BAD_CAST "user");
    xmlNewTextChild(user, NULL, BAD_CAST "uuid", BAD_CAST uuid_str);
    xmlNewTextChild(user, NULL, BAD_CAST "username", BAD_CAST username);
    xmlNewTextChild(user, NULL, BAD_CAST "password", BAD_CAST passwd);
    xmlNewTextChild(user, NULL, BAD_CAST "date", BAD_CAST time_str);
    xmlNewTextChild(user, NULL, BAD_CAST "connected", BAD_CAST "false");
    server_event_user_created(uuid_str, username);
    return user;
}

void user_add(xmlNodePtr user, xmlDocPtr xml_tree)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);

    if (!root)
        return;
    if (strcmp((char *) root->children->name, "users") != 0)
        return;
    xmlAddChild(root->children, user);
}
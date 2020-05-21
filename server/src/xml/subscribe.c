/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe.c
*/

#include <libxml/tree.h>
#include <string.h>

#include "def.h"
#include "exception.h"
#include "logging_server.h"
#include "xml.h"

xmlNodePtr subscribe_create(const char *uid)
{
    xmlNodePtr subscribe;

    subscribe = xmlNewText(BAD_CAST uid);
    return subscribe;
}

exception_t subscribe_add(
    xmlNodePtr subscribe, xmlDocPtr xml_tree, const char *team_uid)
{
    exception_t exception = {NO_ERROR};
    xmlNodePtr team = team_get(xml_tree, team_uid);

    if (!team || !team->children) {
        exception = new_exception(
            OUT_OF_RANGE, "subscribe (xml/subscribe.c)", "Team not found");
        return exception;
    }
    for (xmlNodePtr attr = team->children; attr; attr = attr->next) {
        if (strcmp((char *)attr->name, "subscribes") == 0)
            xmlAddChild(attr, subscribe);
    }
    exception = new_exception(
        OUT_OF_RANGE, "subscribe (xml/subscribe.c)", "Subscribes not found");
    return exception;
}

bool check_users(xmlNodePtr subscribers, const char *user_uid)
{
    if (!subscribers->children) return false;
    for (xmlNodePtr sub = subscribers->children; sub; sub = sub->next) {
        if (strcmp((char *)sub->name, user_uid) == 0) return true;
    }
    return false;
}

bool subscriber_get(
    xmlDocPtr xml_tree, const char *team_uid, const char *user_uid)
{
    xmlNodePtr team = team_get(xml_tree, team_uid);

    if (!team || !team->children) {
        return false;
    }
    for (xmlNodePtr attr = team->children; attr; attr = attr->next) {
        if (strcmp((char *)attr->name, "subscribes") == 0)
            return check_users(attr, user_uid);
    }
    return false;
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe.c
*/

#include <string.h>

#include "def.h"
#include "exception.h"
#include "libxml3.h"
#include "logging_server.h"
#include "xml.h"

xmlNodePtr subscribe_create(const char *uid)
{
    xmlNodePtr subscribe;

    subscribe = xmlNewText(BAD_CAST "uuid", BAD_CAST uid);
    return subscribe;
}

exception_t subscribe_add(
    xmlNodePtr subscribe, xmlDocPtr xml_tree, const char *team_uid)
{
    exception_t exception = {NO_ERROR};
    xmlNodePtr team = team_get(xml_tree, team_uid);

    if (!team || !team->children) {
        exception = new_exception(
            OUT_OF_RANGE, "subscribe_add (xml/subscribe.c)", "Team not found");
        return exception;
    }
    for (xmlNodePtr attr = team->children; attr; attr = attr->next) {
        if (strcmp((char *)attr->name, "subscribes") == 0)
            xmlAddChild(attr, subscribe);
    }
    exception = new_exception(OUT_OF_RANGE, "subscribe_add (xml/subscribe.c)",
        "Subscribes not found");
    return exception;
}

exception_t subscribe_del(
    xmlDocPtr xml_tree, const char *team_uid, const char *user_id)
{
    exception_t exception = {NO_ERROR};
    xmlNodePtr team = team_get(xml_tree, team_uid);
    xmlNodePtr sub = NULL;

    if (!team)
        return new_exception(
            OUT_OF_RANGE, "subscribe_del (xml/subscribe.c)", "Team not found");
    for (xmlNodePtr attr = team->children; attr; attr = attr->next)
        if (strcmp((char *)attr->name, "subscribes") == 0)
            sub = attr;
    if (!sub)
        return new_exception(OUT_OF_RANGE, "subscribe_del (xml/subscribe.c)",
            "Subscribes not found");
    for (sub = sub->children; sub; sub = sub->next)
        if (strcmp((char *)xmlNodeGetContent(sub), user_id) == 0) {
            xmlUnlinkNode(sub);
            xmlFreeNode(sub);
            return exception;
        }
    return exception;
}

static bool check_users(xmlNodePtr subscribers, const char *user_uid)
{
    if (!subscribers->children)
        return false;
    for (xmlNodePtr sub = subscribers->children; sub; sub = sub->next) {
        if (strcmp((char *)xmlNodeGetContent(sub), user_uid) == 0)
            return true;
    }
    return false;
}

bool is_subscribe(
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
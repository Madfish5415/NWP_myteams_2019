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

xml_node_ptr subscribe_create(const char *uid)
{
    xml_node_ptr subscribe;

    subscribe = xml_new_text(BAD_CAST "uuid", BAD_CAST uid);
    return subscribe;
}

exception_t subscribe_add(
    xml_node_ptr subscribe, xml_doc_ptr xml_tree, const char *team_uid)
{
    exception_t exception = {NO_ERROR};
    xml_node_ptr team = team_get(xml_tree, team_uid);

    if (!team || !team->children) {
        exception = new_exception(
            OUT_OF_RANGE, "subscribe_add (xml/subscribe.c)", "Team not found");
        return exception;
    }
    for (xml_node_ptr attr = team->children; attr; attr = attr->next) {
        if (strcmp((char *)attr->name, "subscribes") == 0)
            xml_add_child(attr, subscribe);
    }
    exception = new_exception(OUT_OF_RANGE, "subscribe_add (xml/subscribe.c)",
        "Subscribes not found");
    return exception;
}

exception_t subscribe_del(
    xml_doc_ptr xml_tree, const char *team_uid, const char *user_id)
{
    exception_t exception = {NO_ERROR};
    xml_node_ptr team = team_get(xml_tree, team_uid);
    xml_node_ptr sub = NULL;

    if (!team)
        return new_exception(
            OUT_OF_RANGE, "subscribe_del (xml/subscribe.c)", "Team not found");
    for (xml_node_ptr attr = team->children; attr; attr = attr->next)
        if (strcmp((char *)attr->name, "subscribes") == 0)
            sub = attr;
    if (!sub)
        return new_exception(OUT_OF_RANGE, "subscribe_del (xml/subscribe.c)",
            "Subscribes not found");
    for (sub = sub->children; sub; sub = sub->next)
        if (strcmp((char *)xml_node_get_content(sub), user_id) == 0) {
            xml_unlink_node(sub);
            xml_free_node(sub);
            return exception;
        }
    return exception;
}

static bool check_users(xml_node_ptr subscribers, const char *user_uid)
{
    if (!subscribers->children)
        return false;
    for (xml_node_ptr sub = subscribers->children; sub; sub = sub->next) {
        if (strcmp((char *)xml_node_get_content(sub), user_uid) == 0)
            return true;
    }
    return false;
}

bool is_subscribe(
    xml_doc_ptr xml_tree, const char *team_uid, const char *user_uid)
{
    xml_node_ptr team = team_get(xml_tree, team_uid);

    if (!team || !team->children) {
        return false;
    }
    for (xml_node_ptr attr = team->children; attr; attr = attr->next) {
        if (strcmp((char *)attr->name, "subscribes") == 0)
            return check_users(attr, user_uid);
    }
    return false;
}
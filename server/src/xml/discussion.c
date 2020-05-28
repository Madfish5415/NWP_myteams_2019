/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** discussion.c
*/

#include "libxml2.h"
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "exception.h"
#include "logging_server.h"
#include "xml.h"

xmlNodePtr discussion_create(const char *user_id, const char *user_id2)
{
    xmlNodePtr discussion;
    xmlNodePtr messages;

    discussion = xmlNewNode(NULL, BAD_CAST "discussion");
    xmlNewTextChild(discussion, NULL, BAD_CAST "uuid", BAD_CAST user_id);
    xmlNewTextChild(discussion, NULL, BAD_CAST "uuid", BAD_CAST user_id2);
    messages = xmlNewNode(NULL, BAD_CAST "messages");
    xmlAddChild(discussion, messages);
    return discussion;
}

static bool check_ids(
    xmlNodePtr discussion, const char *user_id, const char *user_id2)
{
    if (strcmp((char *)xmlNodeGetContent(discussion), user_id) == 0 &&
        strcmp((char *)xmlNodeGetContent(discussion->next), user_id2) == 0)
        return true;
    if (strcmp((char *)xmlNodeGetContent(discussion), user_id2) == 0 &&
        strcmp((char *)xmlNodeGetContent(discussion->next), user_id) == 0)
        return true;
    return false;
}

static void add_discussion(xmlNodePtr discussions, const char *user_id,
    const char *user_id2, xmlNodePtr message)
{
    for (xmlNodePtr discussion = discussions->children; discussion;
        discussion = discussion->next) {
        if (!discussion->children)
            return;
        if (check_ids(discussion->children, user_id, user_id2)) {
            xmlAddChild(discussion->children->next->next, message);
            return;
        }
    }
    xmlAddChild(discussions, discussion_create(user_id, user_id2));
    add_discussion(discussions, user_id, user_id2, message);
}

exception_t discussion_add_message(xmlDocPtr xml_tree, const char *user_id,
    const char *user_id2, xmlNodePtr message)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);
    exception_t exception = {NO_ERROR};

    if (!root) {
        exception = new_exception(OUT_OF_RANGE,
            "discussion_add (xml/discussion.c)", "Root of the file not found");
        return exception;
    }
    if (!root->children || !root->children->next ||
        !root->children->next->next) {
        exception = new_exception(OUT_OF_RANGE,
            "discussion_add (xml/discussion.c)", "Discussions not found");
        return exception;
    }
    add_discussion(root->children->next->next, user_id, user_id2, message);
    return exception;
}

xmlNodePtr discussion_get(
    xmlDocPtr xml_tree, const char *user_id, const char *user_id2)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);

    if (!root || !root->children || !root->children->next ||
        !root->children->next->next ||
        strcmp((char *)root->children->next->next->name, "discussions") != 0)
        return NULL;
    for (xmlNodePtr discussion = root->children->next->next->children;
        discussion; discussion = discussion->next) {
        if (check_ids(discussion->children, user_id, user_id2)) {
            return discussion;
        }
    }
    return NULL;
}
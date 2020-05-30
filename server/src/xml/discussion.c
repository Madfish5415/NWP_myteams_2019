/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** discussion.c
*/

#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "exception.h"
#include "libxml3.h"
#include "logging_server.h"
#include "xml.h"

xml_node_ptr discussion_create(const char *user_id, const char *user_id2)
{
    xml_node_ptr discussion;
    xml_node_ptr messages;

    discussion = xml_new_node(BAD_CAST "discussion");
    xml_new_text_child(discussion, BAD_CAST "uuid", BAD_CAST user_id);
    xml_new_text_child(discussion, BAD_CAST "uuid", BAD_CAST user_id2);
    messages = xml_new_node(BAD_CAST "messages");
    xml_add_child(discussion, messages);
    return discussion;
}

static bool check_ids(
    xml_node_ptr discussion, const char *user_id, const char *user_id2)
{
    if (strcmp((char *)xml_node_get_content(discussion), user_id) == 0 &&
        strcmp((char *)xml_node_get_content(discussion->next), user_id2) == 0)
        return true;
    if (strcmp((char *)xml_node_get_content(discussion), user_id2) == 0 &&
        strcmp((char *)xml_node_get_content(discussion->next), user_id) == 0)
        return true;
    return false;
}

static void add_discussion(xml_node_ptr discussions, const char *user_id,
    const char *user_id2, xml_node_ptr message)
{
    for (xml_node_ptr discussion = discussions->children; discussion;
        discussion = discussion->next) {
        if (!discussion->children)
            return;
        if (check_ids(discussion->children, user_id, user_id2)) {
            xml_add_child(discussion->children->next->next, message);
            return;
        }
    }
    xml_add_child(discussions, discussion_create(user_id, user_id2));
    add_discussion(discussions, user_id, user_id2, message);
}

exception_t discussion_add_message(xml_doc_ptr xml_tree, const char *user_id,
    const char *user_id2, xml_node_ptr message)
{
    xml_node_ptr root = xml_doc_get_root_element(xml_tree);
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

xml_node_ptr discussion_get(
    xml_doc_ptr xml_tree, const char *user_id, const char *user_id2)
{
    xml_node_ptr root = xml_doc_get_root_element(xml_tree);

    if (!root || !root->children || !root->children->next ||
        !root->children->next->next ||
        strcmp((char *)root->children->next->next->name, "discussions") != 0)
        return NULL;
    for (xml_node_ptr discussion = root->children->next->next->children;
        discussion; discussion = discussion->next) {
        if (check_ids(discussion->children, user_id, user_id2)) {
            return discussion;
        }
    }
    return NULL;
}
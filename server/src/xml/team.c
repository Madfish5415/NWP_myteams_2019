/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** teams.c
*/

#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "libxml3.h"
#include "logging_server.h"
#include "server.h"
#include "xml.h"

xml_node_ptr team_create(
    const char *team_name, const char *desc, const char *creator)
{
    xml_node_ptr team;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[TIME_SIZE];
    char uuid_str[UUID_SIZE];

    strftime(time_str, sizeof(time_str), "%d-%m-%y %H:%M:%S", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    team = xml_new_node(BAD_CAST "team");
    xml_new_text_child(team, BAD_CAST "uuid", BAD_CAST uuid_str);
    xml_new_text_child(team, BAD_CAST "name", BAD_CAST team_name);
    xml_new_text_child(team, BAD_CAST "desc", BAD_CAST desc);
    xml_new_text_child(team, BAD_CAST "date", BAD_CAST time_str);
    xml_new_text_child(team, BAD_CAST "creator", BAD_CAST creator);
    xml_add_child(team, xml_new_node(BAD_CAST "channels"));
    xml_add_child(team, xml_new_node(BAD_CAST "subscribes"));
    server_event_team_created(uuid_str, team_name, creator);
    return team;
}

exception_t team_add(xml_node_ptr team, xml_doc_ptr xml_tree)
{
    xml_node_ptr root = xml_doc_get_root_element(xml_tree);
    exception_t exception = {NO_ERROR};

    if (!root) {
        exception = new_exception(OUT_OF_RANGE, "team_add (xml/team_add.c)",
            "Root of the file not found");
        return exception;
    }
    if (!root->children || !root->children->next) {
        exception = new_exception(
            OUT_OF_RANGE, "team_add (xml/team_add.c)", "Teams not found");
        return exception;
    }
    if (strcmp((char *)root->children->next->name, "teams") != 0) {
        exception = new_exception(
            OUT_OF_RANGE, "team_add (xml/team_add.c)", "Teams not found");
        return exception;
    }
    xml_add_child(root->children->next, team);
    return exception;
}

xml_node_ptr team_get(xml_doc_ptr xml_tree, const char *team_uid)
{
    xml_node_ptr root = xml_doc_get_root_element(xml_tree);

    if (!root || !root->children || !root->children->next) return NULL;
    if (strcmp((char *)root->children->next->name, "teams") != 0) return NULL;
    if (!root->children->next->children) return NULL;
    for (xml_node_ptr tmp = root->children->next->children; tmp;
            tmp = tmp->next) {
        if (!tmp->children) return NULL;
        if (strcmp((char *)xml_node_get_content(tmp->children), team_uid) == 0)
            return tmp;
    }
    return NULL;
}
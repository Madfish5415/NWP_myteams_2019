/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** teams.c
*/

#include <libxml/tree.h>
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "logging_server.h"

xmlNodePtr team_create(
    const char *team_name, const char *desc, const char *creator)
{
    xmlNodePtr team;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[64];
    char uuid_str[37];

    strftime(time_str, sizeof(time_str), "%c", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    team = xmlNewNode(NULL, BAD_CAST "team");
    xmlNewTextChild(team, NULL, BAD_CAST "uuid", BAD_CAST uuid_str);
    xmlNewTextChild(team, NULL, BAD_CAST "name", BAD_CAST team_name);
    xmlNewTextChild(team, NULL, BAD_CAST "desc", BAD_CAST desc);
    xmlNewTextChild(team, NULL, BAD_CAST "date", BAD_CAST time_str);
    xmlNewTextChild(team, NULL, BAD_CAST "creator", BAD_CAST creator);
    server_event_team_created(uuid_str, team_name, creator);
    return team;
}

void team_add(xmlNodePtr team, xmlDocPtr xml_tree)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);

    if (!root) return;
    if (strcmp((char *)root->children->next->name, "teams") != 0) return;
    xmlAddChild(root->children->next, team);
}

xmlNodePtr team_get(xmlDocPtr xml_tree, const char *team_uid)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);

    if (!root || !root->children || !root->children->next) return NULL;
    if (strcmp((char *)root->children->next->name, "teams") != 0) return NULL;
    if (!root->children->next->children) return NULL;
    for (xmlNodePtr tmp = root->children->next->children; tmp;
         tmp = tmp->next) {
        if (!tmp->children) return NULL;
        if (strcmp((char *)tmp->children->name, team_uid) == 0) return tmp;
    }
    return NULL;
}
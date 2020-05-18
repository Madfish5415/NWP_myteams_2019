/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml.h
*/

#ifndef NWP_MYTEAMS_2019_XML_H
#define NWP_MYTEAMS_2019_XML_H

#include "libxml/tree.h"
#include "libxml/parser.h"

void team_add(xmlNodePtr team, xmlDocPtr xml_tree);
xmlNodePtr team_create(const char *team_name, const char *desc, const char *creator);
xmlNodePtr team_get(xmlDocPtr xml_tree, const char *team_uid);

void user_add(xmlNodePtr user, xmlDocPtr xml_tree);
xmlNodePtr user_create(const char *username, const char *passwd);

void channel_add(xmlNodePtr channel, xmlDocPtr xml_tree, const char *team_uid);
xmlNodePtr channel_create(const char *channel_name, const char *desc, const char *creator, const char *team_uid);


#endif  // NWP_MYTEAMS_2019_XML_H

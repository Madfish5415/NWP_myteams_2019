/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml.h
*/

#ifndef NWP_MYTEAMS_2019_XML_H
#define NWP_MYTEAMS_2019_XML_H

#include "exception.h"
#include "libxml/parser.h"
#include "libxml/tree.h"

exception_t team_add(xmlNodePtr team, xmlDocPtr xml_tree);
xmlNodePtr team_create(
    const char *team_name, const char *desc, const char *creator);
xmlNodePtr team_get(xmlDocPtr xml_tree, const char *team_uid);

exception_t user_add(xmlNodePtr user, xmlDocPtr xml_tree);
xmlNodePtr user_create(const char *username, const char *passwd);

exception_t channel_add(xmlNodePtr channel, xmlDocPtr xml_tree, const char *team_uid);
xmlNodePtr channel_create(const char *channel_name, const char *desc,
    const char *creator, const char *team_uid);
xmlNodePtr channel_get(
    xmlDocPtr xml_tree, const char *team_uid, const char *channel_uid);

xmlNodePtr thread_create(const char *thread_name, const char *body,
                         const char *creator, const char *channel_uid);
exception_t thread_add(xmlNodePtr thread, xmlDocPtr xml_tree, const char *team_uid,
                const char *channel_uid);
xmlNodePtr thread_get(xmlDocPtr xml_tree, const char *team_uid,
                      const char *channel_uid, const char *thread_uid);
#endif  // NWP_MYTEAMS_2019_XML_H

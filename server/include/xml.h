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

/*  belongs_to.c  */
bool channel_belongs_to_team(
    xmlDocPtr xml_tree, const char *channel_uuid, const char *team_uuid);
bool thread_belongs_to_channel(
    xmlDocPtr xml_tree, const char *thread_uuid, const char *channel_uuid);

/*  channel.c  */
exception_t channel_add(
    xmlNodePtr channel, xmlDocPtr xml_tree, const char *team_uid);
xmlNodePtr channel_create(const char *channel_name, const char *desc,
    const char *creator, const char *team_uid);
xmlNodePtr channel_get(xmlDocPtr xml_tree, const char *channel_uid);
xmlNodePtr get_channels_team(xmlNodePtr team);

/*  discussion.c  */
xmlNodePtr discussion_create(const char *user_id, const char *user_id2);
exception_t discussion_add_message(xmlDocPtr xml_tree, const char *user_id,
    const char *user_id2, xmlNodePtr message);
xmlNodePtr discussion_get(
    xmlDocPtr xml_tree, const char *user_id, const char *user_id2);

/*  message.c  */
xmlNodePtr message_create(const char *body, const char *creator);
xmlNodePtr message_thread_create(
    const char *body, const char *creator, const char *thread_uid);
xmlNodePtr message_discussion_create(
    const char *sender_id, const char *receiver_id, const char *body);
exception_t message_add(
    xmlNodePtr message, xmlDocPtr xml_tree, const char *thread_uid);

/*  subscribe.c  */
xmlNodePtr subscribe_create(const char *uid);
exception_t subscribe_add(
    xmlNodePtr subscribe, xmlDocPtr xml_tree, const char *team_uid);
exception_t subscribe_del(
    xmlDocPtr xml_tree, const char *team_uid, const char *user_id);
bool is_subscribe(
    xmlDocPtr xml_tree, const char *team_uid, const char *user_uid);

/*  team.c  */
exception_t team_add(xmlNodePtr team, xmlDocPtr xml_tree);
xmlNodePtr team_create(
    const char *team_name, const char *desc, const char *creator);
xmlNodePtr team_get(xmlDocPtr xml_tree, const char *team_uid);

/*  thread.c  */
xmlNodePtr thread_create(const char *thread_name, const char *body,
    const char *creator, const char *channel_uid);
exception_t thread_add(
    xmlNodePtr thread, xmlDocPtr xml_tree, const char *channel_uid);
xmlNodePtr thread_get(xmlDocPtr xml_tree, const char *thread_uid);
xmlNodePtr get_threads_team(xmlNodePtr team);

/*  user.c  */
exception_t user_add(xmlNodePtr user, xmlDocPtr xml_tree);
xmlNodePtr user_create(const char *username, const char *passwd);
xmlNodePtr user_get_by_name(xmlDocPtr xml_tree, const char *username);
xmlNodePtr user_get_by_uuid(xmlDocPtr xml_tree, const char *uuid);

typedef struct node_s {
    struct node_s *next;
    struct node_s *prev;
    struct node_s *parent;
    struct node_s *children;
    char *content;
    char *name;
} node_t;

#endif // NWP_MYTEAMS_2019_XML_H

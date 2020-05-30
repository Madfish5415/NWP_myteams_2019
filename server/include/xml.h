/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml.h
*/

#ifndef NWP_MYTEAMS_2019_XML_H
#define NWP_MYTEAMS_2019_XML_H

#include "exception.h"
#include "libxml3.h"

/*  belongs_to.c  */
bool channel_belongs_to_team(
    xml_doc_ptr xml_tree, const char *channel_uuid, const char *team_uuid);
bool thread_belongs_to_channel(
    xml_doc_ptr xml_tree, const char *thread_uuid, const char *channel_uuid);

/*  channel.c  */
exception_t channel_add(
    xml_node_ptr channel, xml_doc_ptr xml_tree, const char *team_uid);
xml_node_ptr channel_create(const char *channel_name, const char *desc,
    const char *creator, const char *team_uid);
xml_node_ptr channel_get(xml_doc_ptr xml_tree, const char *channel_uid);
xml_node_ptr get_channels_team(xml_node_ptr team);

/*  discussion.c  */
xml_node_ptr discussion_create(const char *user_id, const char *user_id2);
exception_t discussion_add_message(xml_doc_ptr xml_tree, const char *user_id,
    const char *user_id2, xml_node_ptr message);
xml_node_ptr discussion_get(
    xml_doc_ptr xml_tree, const char *user_id, const char *user_id2);

/*  message.c  */
xml_node_ptr message_create(const char *body, const char *creator);
xml_node_ptr message_thread_create(
    const char *body, const char *creator, const char *thread_uid);
xml_node_ptr message_discussion_create(
    const char *sender_id, const char *receiver_id, const char *body);
exception_t message_add(
    xml_node_ptr message, xml_doc_ptr xml_tree, const char *thread_uid);

/*  subscribe.c  */
xml_node_ptr subscribe_create(const char *uid);
exception_t subscribe_add(
    xml_node_ptr subscribe, xml_doc_ptr xml_tree, const char *team_uid);
exception_t subscribe_del(
    xml_doc_ptr xml_tree, const char *team_uid, const char *user_id);
bool is_subscribe(
    xml_doc_ptr xml_tree, const char *team_uid, const char *user_uid);

/*  team.c  */
exception_t team_add(xml_node_ptr team, xml_doc_ptr xml_tree);
xml_node_ptr team_create(
    const char *team_name, const char *desc, const char *creator);
xml_node_ptr team_get(xml_doc_ptr xml_tree, const char *team_uid);

/*  thread.c  */
xml_node_ptr thread_create(const char *thread_name, const char *body,
    const char *creator, const char *channel_uid);
exception_t thread_add(
    xml_node_ptr thread, xml_doc_ptr xml_tree, const char *channel_uid);
xml_node_ptr thread_get(xml_doc_ptr xml_tree, const char *thread_uid);
xml_node_ptr get_threads_team(xml_node_ptr team);

/*  user.c  */
exception_t user_add(xml_node_ptr user, xml_doc_ptr xml_tree);
xml_node_ptr user_create(const char *username, const char *passwd);
xml_node_ptr user_get_by_name(xml_doc_ptr xml_tree, const char *username);
xml_node_ptr user_get_by_uuid(xml_doc_ptr xml_tree, const char *uuid);


#endif // NWP_MYTEAMS_2019_XML_H

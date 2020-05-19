/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread.c
*/

#include <libxml/tree.h>
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "logging_server.h"
#include "xml.h"

xmlNodePtr thread_create(const char *thread_name, const char *body,
    const char *creator, const char *channel_uid)
{
    xmlNodePtr thread;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[64];
    char uuid_str[37];

    strftime(time_str, sizeof(time_str), "%c", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    thread = xmlNewNode(NULL, BAD_CAST "channel");
    xmlNewTextChild(thread, NULL, BAD_CAST "uuid", BAD_CAST uuid_str);
    xmlNewTextChild(thread, NULL, BAD_CAST "name", BAD_CAST thread_name);
    xmlNewTextChild(thread, NULL, BAD_CAST "body", BAD_CAST body);
    xmlNewTextChild(thread, NULL, BAD_CAST "date", BAD_CAST time_str);
    xmlNewTextChild(thread, NULL, BAD_CAST "creator", BAD_CAST creator);
    server_event_thread_created(channel_uid, uuid_str, creator, body);
    return thread;
}

void thread_add(xmlNodePtr thread, xmlDocPtr xml_tree, const char *team_uid,
    const char *channel_uid)
{
    xmlNodePtr channel = channel_get(xml_tree, team_uid, channel_uid);

    if (!channel || !channel->children) return;
    for (xmlNodePtr threads = channel->children; threads;
         threads = threads->next) {
        if (strcmp((char *)threads->name, "threads") == 0) {
            xmlAddChild(threads, thread);
            break;
        }
    }
}

xmlNodePtr thread_get(xmlDocPtr xml_tree, const char *team_uid,
    const char *channel_uid, const char *thread_uid)
{
    xmlNodePtr channel = channel_get(xml_tree, team_uid, channel_uid);
    xmlNodePtr tmp = NULL;

    if (!channel || !channel->children) return NULL;
    for (tmp = channel->children; tmp; tmp = tmp->next) {
        if (strcmp((char *)tmp->name, "threads") == 0) break;
    }
    if (!tmp || !tmp->children) return NULL;
    for (tmp = tmp->children; tmp; tmp = tmp->next) {
        if (!tmp->children) return NULL;
        if (strcmp((char *)tmp->children->name, thread_uid) == 0) return tmp;
    }
    return tmp;
}
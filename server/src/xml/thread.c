/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread.c
*/

#include "libxml2.h"
#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "exception.h"
#include "logging_server.h"
#include "xml.h"

xmlNodePtr thread_create(const char *thread_name, const char *body,
    const char *creator, const char *channel_uid)
{
    xmlNodePtr thread;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[TIME_SIZE];
    char uuid_str[UUID_SIZE];

    strftime(time_str, sizeof(time_str), "%d-%m-%y %H:%M:%S", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    thread = xmlNewNode(NULL, BAD_CAST "thread");
    xmlNewTextChild(thread, NULL, BAD_CAST "uuid", BAD_CAST uuid_str);
    xmlNewTextChild(thread, NULL, BAD_CAST "name", BAD_CAST thread_name);
    xmlNewTextChild(thread, NULL, BAD_CAST "body", BAD_CAST body);
    xmlNewTextChild(thread, NULL, BAD_CAST "date", BAD_CAST time_str);
    xmlNewTextChild(thread, NULL, BAD_CAST "creator", BAD_CAST creator);
    xmlAddChild(thread, xmlNewNode(NULL, BAD_CAST "messages"));
    server_event_thread_created(channel_uid, uuid_str, creator, body);
    return thread;
}

exception_t thread_add(
    xmlNodePtr thread, xmlDocPtr xml_tree, const char *channel_uid)
{
    exception_t exception = {NO_ERROR};
    xmlNodePtr channel = channel_get(xml_tree, channel_uid);

    if (!channel || !channel->children) {
        exception = new_exception(
            OUT_OF_RANGE, "thread_add (xml/thread.c)", "Channel not found");
        return exception;
    }
    for (xmlNodePtr threads = channel->children; threads;
        threads = threads->next) {
        if (strcmp((char *)threads->name, "threads") == 0) {
            xmlAddChild(threads, thread);
            return exception;
        }
    }
    exception = new_exception(
        OUT_OF_RANGE, "thread_add (xml/thread.c)", "Threads not found");
    return exception;
}

static xmlNodePtr find_thread(xmlNodePtr channels, const char *thread_uid)
{
    xmlNodePtr channel = NULL;
    xmlNodePtr attr = NULL;
    xmlNodePtr thread = NULL;

    if (!channels->children) return NULL;
    for (channel = channels->children; channel; channel = channel->next) {
        if (!channel->children) continue;
        for (attr = channel->children; attr; attr = attr->next)
            if (strcmp((char *)attr->name, "threads") == 0) break;
        if (!attr->children) continue;
        for (thread = attr->children; thread; thread = thread->next) {
            if (!thread->children) continue;
            if (strcmp((char *)xmlNodeGetContent(thread->children),
                    thread_uid) == 0) return thread;
        }
    }
    return NULL;
}

xmlNodePtr get_threads_channel(xmlNodePtr team)
{
    if (!team || !team->children)
        return NULL;
    for (xmlNodePtr tmp = team->children; tmp; tmp = tmp->next) {
        if (strcmp((char *)tmp->name, "threads") == 0)
            return tmp;
    }
    return NULL;
}

xmlNodePtr thread_get(xmlDocPtr xml_tree, const char *thread_uid)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);
    xmlNodePtr res = NULL;
    xmlNodePtr channels = NULL;

    if (!root || !root->children || !root->children->next ||
        !root->children->next->children)
        return NULL;
    for (xmlNodePtr team = root->children->next->children; team;
        team = team->next) {
        channels = get_channels_team(team);
        if (!channels || !channels->children)
            return NULL;
        res = find_thread(channels, thread_uid);
        if (res)
            return res;
    }
    return NULL;
}
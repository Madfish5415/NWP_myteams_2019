/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread.c
*/

#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "exception.h"
#include "libxml3.h"
#include "logging_server.h"
#include "xml.h"

xml_node_ptr thread_create(const char *thread_name, const char *body,
    const char *creator, const char *channel_uid)
{
    xml_node_ptr thread;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[TIME_SIZE];
    char uuid_str[UUID_SIZE];

    strftime(time_str, sizeof(time_str), "%d-%m-%y %H:%M:%S", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    thread = new_node(BAD_CAST "thread");
    new_text_child(thread, BAD_CAST "uuid", BAD_CAST uuid_str);
    new_text_child(thread, BAD_CAST "name", BAD_CAST thread_name);
    new_text_child(thread, BAD_CAST "body", BAD_CAST body);
    new_text_child(thread, BAD_CAST "date", BAD_CAST time_str);
    new_text_child(thread, BAD_CAST "creator", BAD_CAST creator);
    add_child(thread, new_node(BAD_CAST "messages"));
    server_event_thread_created(channel_uid, uuid_str, creator, body);
    return thread;
}

exception_t thread_add(
    xml_node_ptr thread, xml_doc_ptr xml_tree, const char *channel_uid)
{
    exception_t exception = {NO_ERROR};
    xml_node_ptr channel = channel_get(xml_tree, channel_uid);

    if (!channel || !channel->children) {
        exception = new_exception(
            OUT_OF_RANGE, "thread_add (xml/thread.c)", "Channel not found");
        return exception;
    }
    for (xml_node_ptr threads = channel->children; threads;
        threads = threads->next) {
        if (strcmp((char *)threads->name, "threads") == 0) {
            add_child(threads, thread);
            return exception;
        }
    }
    exception = new_exception(
        OUT_OF_RANGE, "thread_add (xml/thread.c)", "Threads not found");
    return exception;
}

static xml_node_ptr find_thread(xml_node_ptr channels, const char *thread_uid)
{
    xml_node_ptr channel = NULL;
    xml_node_ptr attr = NULL;
    xml_node_ptr thread = NULL;

    if (!channels->children) return NULL;
    for (channel = channels->children; channel; channel = channel->next) {
        if (!channel->children) continue;
        for (attr = channel->children; attr; attr = attr->next)
            if (strcmp((char *)attr->name, "threads") == 0) break;
        if (!attr->children) continue;
        for (thread = attr->children; thread; thread = thread->next) {
            if (!thread->children) continue;
            if (strcmp((char *)node_get_content(thread->children),
                    thread_uid) == 0) return thread;
        }
    }
    return NULL;
}

xml_node_ptr get_threads_channel(xml_node_ptr team)
{
    if (!team || !team->children)
        return NULL;
    for (xml_node_ptr tmp = team->children; tmp; tmp = tmp->next) {
        if (strcmp((char *)tmp->name, "threads") == 0)
            return tmp;
    }
    return NULL;
}

xml_node_ptr thread_get(xml_doc_ptr xml_tree, const char *thread_uid)
{
    xml_node_ptr root = doc_get_root_element(xml_tree);
    xml_node_ptr res = NULL;
    xml_node_ptr channels = NULL;

    if (!root || !root->children || !root->children->next ||
        !root->children->next->children)
        return NULL;
    for (xml_node_ptr team = root->children->next->children; team;
        team = team->next) {
        channels = get_channels_team(team);
        if (!channels || !channels->children)
            continue;
        res = find_thread(channels, thread_uid);
        if (res)
            return res;
    }
    return NULL;
}
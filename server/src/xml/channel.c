/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel.c
*/

#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "libxml3.h"
#include "logging_server.h"
#include "xml.h"

xmlNodePtr channel_create(const char *channel_name, const char *desc,
    const char *creator, const char *team_uid)
{
    xmlNodePtr channel;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[TIME_SIZE];
    char uuid_str[UUID_SIZE];

    strftime(time_str, sizeof(time_str), "%d-%m-%y %H:%M:%S", localt);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);
    channel = xmlNewNode(BAD_CAST "channel");
    xmlNewTextChild(channel, BAD_CAST "uuid", BAD_CAST uuid_str);
    xmlNewTextChild(channel, BAD_CAST "name", BAD_CAST channel_name);
    xmlNewTextChild(channel, BAD_CAST "desc", BAD_CAST desc);
    xmlNewTextChild(channel, BAD_CAST "date", BAD_CAST time_str);
    xmlNewTextChild(channel, BAD_CAST "creator", BAD_CAST creator);
    xmlAddChild(channel, xmlNewNode(BAD_CAST "threads"));
    server_event_channel_created(team_uid, uuid_str, channel_name);
    return channel;
}

exception_t channel_add(
    xmlNodePtr channel, xmlDocPtr xml_tree, const char *team_uid)
{
    xmlNodePtr team = team_get(xml_tree, team_uid);
    exception_t exception = {NO_ERROR};

    if (!team || !team->children) {
        exception = new_exception(
            OUT_OF_RANGE, "channel_add (xml/channel.c)", "Team not found");
        return exception;
    }
    for (xmlNodePtr channels = team->children; channels;
        channels = channels->next) {
        if (strcmp((char *)channels->name, "channels") == 0) {
            xmlAddChild(channels, channel);
            return exception;
        }
    }
    exception = new_exception(
        OUT_OF_RANGE, "channel_add (xml/channel.c)", "Channels not found");
    return exception;
}

static xmlNodePtr find_channel(xmlNodePtr channels, const char *channel_uid)
{
    if (strcmp((char *)channels->name, "channels") != 0)
        return NULL;
    if (!channels->children)
        return NULL;
    for (xmlNodePtr channel = channels->children; channel;
        channel = channel->next) {
        if (!channel->children)
            return NULL;
        if (strcmp((char *)xmlNodeGetContent(channel->children), channel_uid) ==
            0)
            return channel;
    }
    return NULL;
}

xmlNodePtr channel_get(xmlDocPtr xml_tree, const char *channel_uid)
{
    xmlNodePtr root = xmlDocGetRootElement(xml_tree);
    xmlNodePtr res = NULL;

    if (!root || !root->children || !root->children->next ||
        !root->children->next->children)
        return NULL;
    for (xmlNodePtr team = root->children->next->children; team;
        team = team->next) {
        for (xmlNodePtr attr = team->children; attr; attr = attr->next) {
            res = find_channel(attr, channel_uid);
            if (res)
                return res;
        }
    }
    return NULL;
}

xmlNodePtr get_channels_team(xmlNodePtr team)
{
    if (!team || !team->children)
        return NULL;
    for (xmlNodePtr tmp = team->children; tmp; tmp = tmp->next) {
        if (strcmp((char *)tmp->name, "channels") == 0)
            return tmp;
    }
    return NULL;
}
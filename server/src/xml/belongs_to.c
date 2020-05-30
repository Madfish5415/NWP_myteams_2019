/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** belongs_to.c
*/

#include <string.h>

#include "xml.h"

bool channel_belongs_to_team(
    xmlDocPtr xml_tree, const char *channel_uuid, const char *team_uuid)
{
    xmlNodePtr team = team_get(xml_tree, team_uuid);

    if (!team)
        return false;
    for (xmlNodePtr channel =
        team->children->next->next->next->next->next->children;
        channel; channel = channel->next) {
        if (strcmp((char *)xmlNodeGetContent(channel->children),
                channel_uuid) == 0)
            return true;
    }
    return false;
}

bool thread_belongs_to_channel(
    xmlDocPtr xml_tree, const char *thread_uuid, const char *channel_uuid)
{
    xmlNodePtr channel = channel_get(xml_tree, channel_uuid);

    if (!channel)
        return false;
    for (xmlNodePtr thread =
        channel->children->next->next->next->next->next->children;
        thread; thread = thread->next) {
        if (strcmp((char *)xmlNodeGetContent(thread->children),
            thread_uuid) == 0)
            return true;
    }
    return false;
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlNode.c
*/

#include <stdlib.h>
#include <string.h>

#include "libxml3.h"

char *xml_node_get_content(xml_node_ptr cur)
{
    if (!cur)
        return NULL;
    return cur->content;
}

xml_node_ptr xml_node_set_content(xml_node_ptr cur, const char *content)
{
    if (!cur)
        return NULL;
    if (cur->content)
        free(cur->content);
    cur->content = (content) ? strdup(content) : NULL;
    return cur;
}
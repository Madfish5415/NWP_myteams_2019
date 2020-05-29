/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlFree.c
*/

#include <stdlib.h>

#include "libxml3.h"

void xmlFreeNode(xmlNodePtr cur)
{
    if (!cur)
        return;
    if (cur->children) {
        xmlFreeNode(cur->children);
    }
    if (cur->next) {
        xmlFreeNode(cur->next);
    }
    if (cur->name) free(cur->name);
    if (cur->content) free(cur->content);
    free(cur);
}

void xmlFreeDoc(xmlDocPtr doc)
{
    if (!doc) return;
    if (doc->name) free(doc->name);
    if (doc->encoding) free(doc->encoding);
    if (doc->version) free(doc->version);
    if (doc->children) xmlFreeNode(doc->children);
    free(doc);
}
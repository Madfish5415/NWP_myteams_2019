/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlNew.c
*/

#include <string.h>
#include <stdlib.h>

#include "libxml3.h"

xmlNodePtr xmlNewNode(const char *name)
{
    xmlNodePtr node = NULL;

    node = malloc(sizeof(xmlNode));
    if (!node)
        return NULL;
    node->children = NULL;
    node->content = NULL;
    node->next = NULL;
    node->parent = NULL;
    node->prev = NULL;
    node->last = NULL;
    node->name = (name) ? strdup(name) : NULL;
    return node;
}

xmlNodePtr xmlNewText(const char *content)
{
    xmlNodePtr node = NULL;

    node = malloc(sizeof(xmlNode));
    if (!node)
        return NULL;
    node->children = NULL;
    node->next = NULL;
    node->parent = NULL;
    node->prev = NULL;
    node->name = NULL;
    node->last = NULL;
    node->content = (content) ? strdup(content) : NULL;
    return node;
}

xmlNodePtr xmlNewTextChild(
    xmlNodePtr parent, const char *name, const char *content)
{
    xmlNodePtr node = NULL;

    if (!parent)
        return NULL;
    node = malloc(sizeof(xmlNode));
    if (!node)
        return NULL;
    node->children = NULL;
    node->next = NULL;
    node->prev = NULL;
    node->last = NULL;
    node->parent = parent;
    node->name = (name) ? strdup(name) : NULL;
    node->content = (content) ? strdup(content) : NULL;
    return node;
}

xmlDocPtr xmlNewDoc(const char *version)
{
    xmlDocPtr doc = NULL;

    doc = malloc(sizeof(xmlDoc));
    if (!doc)
        return NULL;
    doc->children = NULL;
    doc->encoding = NULL;
    doc->name = NULL;
    doc->version = (version) ? strdup(version) : NULL;
}
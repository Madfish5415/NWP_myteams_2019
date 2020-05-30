/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlNew.c
*/

#include <string.h>
#include <stdlib.h>

#include "libxml3.h"

xml_node_ptr xml_new_node(const char *name)
{
    xml_node_ptr node = NULL;

    node = malloc(sizeof(xml_node));
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

xml_node_ptr xml_new_text(const char *name, const char *content)
{
    xml_node_ptr node = NULL;

    node = malloc(sizeof(xml_node));
    if (!node)
        return NULL;
    node->children = NULL;
    node->next = NULL;
    node->parent = NULL;
    node->prev = NULL;
    node->name = (name) ? strdup(name) : NULL;
    node->last = NULL;
    node->content = (content) ? strdup(content) : NULL;
    return node;
}

xml_node_ptr xml_new_text_child(
    xml_node_ptr parent, const char *name, const char *content)
{
    xml_node_ptr node = NULL;

    if (!parent)
        return NULL;
    node = malloc(sizeof(xml_node));
    if (!node)
        return NULL;
    node->children = NULL;
    node->next = NULL;
    node->prev = NULL;
    node->last = NULL;
    node->parent = NULL;
    node->name = (name) ? strdup(name) : NULL;
    node->content = (content) ? strdup(content) : NULL;
    xml_add_child(parent, node);
    return node;
}

xml_doc_ptr xml_new_doc(const char *version)
{
    xml_doc_ptr doc = NULL;

    doc = malloc(sizeof(xml_doc));
    if (!doc)
        return NULL;
    doc->children = NULL;
    doc->encoding = NULL;
    doc->name = NULL;
    doc->version = (version) ? strdup(version) : NULL;
    return doc;
}
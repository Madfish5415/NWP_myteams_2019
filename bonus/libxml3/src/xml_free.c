/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlFree.c
*/

#include <stdlib.h>

#include "libxml3.h"

void free_node(xml_node_ptr cur)
{
    if (!cur)
        return;
    if (cur->children) {
        free_node(cur->children);
    }
    if (cur->next) {
        free_node(cur->next);
    }
    if (cur->name) free(cur->name);
    if (cur->content) free(cur->content);
    free(cur);
}

void free_doc(xml_doc_ptr doc)
{
    if (!doc) return;
    if (doc->name) free(doc->name);
    if (doc->encoding) free(doc->encoding);
    if (doc->version) free(doc->version);
    if (doc->children)
        free_node(doc->children);
    free(doc);
}
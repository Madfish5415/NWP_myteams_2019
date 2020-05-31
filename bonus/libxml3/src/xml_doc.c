/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlDoc.c
*/

#include <stdlib.h>

#include "libxml3.h"

xml_node_ptr doc_get_root_element(xml_doc_ptr doc)
{
    if (!doc)
        return NULL;
    return doc->children;
}

xml_node_ptr doc_set_root_element(xml_doc_ptr doc, xml_node_ptr root)
{
    if (!doc || !root)
        return NULL;
    if (doc->children)
        free(doc->children);
    doc->children = root;
    return root;
}
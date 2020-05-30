/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlDoc.c
*/

#include <stdlib.h>

#include "libxml3.h"

xmlNodePtr xmlDocGetRootElement(xmlDocPtr doc)
{
    if (!doc)
        return NULL;
    return doc->children;
}

xmlNodePtr xmlDocSetRootElement(xmlDocPtr doc, xmlNodePtr root)
{
    if (!doc || !root)
        return NULL;
    if (doc->children)
        free(doc->children);
    doc->children = root;
    return root;
}
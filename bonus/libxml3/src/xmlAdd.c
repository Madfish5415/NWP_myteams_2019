/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlAdd.c
*/

#include <stdlib.h>

#include "libxml3.h"

xmlNodePtr xmlAddChild(xmlNodePtr parent, xmlNodePtr cur)
{
    if (parent == NULL || cur == NULL)
        return NULL;

    if (parent->children == NULL) {
        parent->children = cur;
        cur->parent = parent;
    } else {
        xmlAddSibling(parent->children, cur);
    }
    return cur;
}

xmlNodePtr xmlAddPrevSibling(xmlNodePtr cur, xmlNodePtr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    if (cur->prev == NULL) {
        cur->prev = elem;
        elem->next = cur;
        elem->parent = cur->parent;
        if (cur->parent->children == cur)
            cur->parent->children = elem;
    } else {
        xmlAddPrevSibling(cur->prev, elem);
    }
    return elem;
}

xmlNodePtr xmlAddSibling(xmlNodePtr cur, xmlNodePtr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    if (cur->next == NULL) {
        cur->next = elem;
        elem->prev = cur;
        elem->parent = cur->parent;
    } else {
        xmlAddSibling(cur->next, elem);
    }
    return elem;
}
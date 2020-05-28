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

    xmlUnlinkNode(cur);
    if (parent->children == NULL && parent->last == NULL) {
        parent->children = cur;
        parent->last = cur;
        cur->parent = parent;
    } else {
        if (parent->children == NULL || parent->last == NULL)
            return NULL;
        parent->last->next = cur;
        cur->prev = parent->last->next;
        parent->last = cur;
    }
    return cur;
}

xmlNodePtr xmlAddNextSibling(xmlNodePtr cur, xmlNodePtr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    xmlUnlinkNode(elem);
    if (elem->parent != NULL) {
        elem->parent = cur->parent;
        if (elem->parent->last == cur)
            elem->parent->last = elem;
    }
    if (cur->next != NULL) {
        cur->next->prev = elem;
        elem->next = cur->next;
    }
    cur->next = elem;
    elem->prev = cur;
    return elem;
}

xmlNodePtr xmlAddPrevSibling(xmlNodePtr cur, xmlNodePtr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    xmlUnlinkNode(elem);
    if (elem->parent != NULL) {
        elem->parent = cur->parent;
        if (elem->parent->children == cur)
            elem->parent->children = elem;
    }
    if (cur->prev != NULL) {
        cur->prev->next = elem;
        elem->prev = cur->prev;
    }
    cur->prev = elem;
    elem->next = cur;
    return elem;
}

xmlNodePtr xmlAddSibling(xmlNodePtr cur, xmlNodePtr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    xmlUnlinkNode(elem);
    if (cur->next == NULL) {
        xmlAddNextSibling(cur, elem);
    } else {
        xmlAddSibling(cur->next, elem);
    }
    return elem;
}
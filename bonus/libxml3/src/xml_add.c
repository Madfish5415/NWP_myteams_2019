/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlAdd.c
*/

#include <stdlib.h>

#include "libxml3.h"

xml_node_ptr xml_add_child(xml_node_ptr parent, xml_node_ptr cur)
{
    if (parent == NULL || cur == NULL)
        return NULL;

    xml_unlink_node(cur);
    if (parent->children == NULL && parent->last == NULL) {
        parent->children = cur;
        parent->last = cur;
        cur->parent = parent;
    } else {
        if (parent->children == NULL || parent->last == NULL)
            return NULL;
        cur->prev = parent->last;
        parent->last->next = cur;
        parent->last = cur;
        cur->parent = parent;
    }
    return cur;
}

xml_node_ptr xml_add_next_sibling(xml_node_ptr cur, xml_node_ptr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    xml_unlink_node(elem);
    if (cur->parent != NULL) {
        elem->parent = cur->parent;
        if (cur->parent->last == cur)
            cur->parent->last = elem;
    }
    if (cur->next != NULL) {
        cur->next->prev = elem;
        elem->next = cur->next;
    }
    cur->next = elem;
    elem->prev = cur;
    return elem;
}

xml_node_ptr xml_add_prev_sibling(xml_node_ptr cur, xml_node_ptr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    xml_unlink_node(elem);
    if (cur->parent != NULL) {
        elem->parent = cur->parent;
        if (cur->parent->children == cur)
            cur->parent->children = elem;
    }
    if (cur->prev != NULL) {
        cur->prev->next = elem;
        elem->prev = cur->prev;
    }
    cur->prev = elem;
    elem->next = cur;
    return elem;
}

xml_node_ptr xml_add_sibling(xml_node_ptr cur, xml_node_ptr elem)
{
    if (cur == NULL || elem == NULL)
        return NULL;

    xml_unlink_node(elem);
    if (cur->next == NULL) {
        xml_add_next_sibling(cur, elem);
    } else {
        xml_add_sibling(cur->next, elem);
    }
    return elem;
}
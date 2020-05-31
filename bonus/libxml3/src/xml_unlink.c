/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlUnlink.c
*/

#include <stdlib.h>

#include "libxml3.h"

void unlink_node(xml_node_ptr cur)
{
    if (cur == NULL)
        return;

    if (cur->prev) cur->prev->next = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    if (cur->parent) {
        if (cur->parent->last == cur) cur->parent->last = cur->prev;
        if (cur->parent->children == cur) cur->parent->children = cur->next;
    }
    cur->prev = NULL;
    cur->next = NULL;
    cur->parent = NULL;
}
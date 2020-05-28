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
        for (xmlNodePtr tmp = cur->children; tmp; tmp = tmp->next)
            xmlFreeNode(tmp);
    }
    free(cur);
}
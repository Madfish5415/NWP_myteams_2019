/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** libxml2.h
*/

#ifndef NWP_MYTEAMS_2019_LIBXML2_H
#define NWP_MYTEAMS_2019_LIBXML2_H

typedef struct _xmlNode {
    struct _xmlNode *next;
    struct _xmlNode *prev;
    struct _xmlNode *parent;
    struct _xmlNode *children;
    char *content;
    char *name;
} xmlNode;

typedef xmlNode* xmlNodePtr;

#endif // NWP_MYTEAMS_2019_LIBXML2_H

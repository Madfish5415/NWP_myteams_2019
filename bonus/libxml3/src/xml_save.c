/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlSave.c
*/

#include <stdio.h>

#include "libxml3.h"

void write_children(FILE *file, xmlNodePtr node, int depth, int format)
{
    if (!node || !node->name)
        return;
    if (node->content) {
        fprintf(file, "%*s<%s>%s</%s>\n", depth * format, "", node->name,
            node->content, node->name);
        return;
    }
    fprintf(file, "%*s<%s>\n", depth * format, "", node->name);
    if (node->children) {
        for (xmlNodePtr child = node->children; child; child = child->next) {
            write_children(file, child, depth + 1, format);
        }
    }
    fprintf(file, "%*s</%s>\n", depth * format, "", node->name);
}

void write_file(FILE *file, xmlNodePtr root, int format)
{
    int depth = 0;

    if (root->name)
        fprintf(file, "%*s<%s>\n", depth * format, "", root->name);
    if (root->children) {
        for (xmlNodePtr child = root->children; child; child = child->next) {
            write_children(file, child, depth + 1, format);
        }
    }
    if (root->name)
        fprintf(file, "%*s</%s>", depth * format, "", root->name);
}

void write_doc(FILE *file, xmlDocPtr doc)
{
    if (!doc->version && !doc->encoding)
        return;
    if (!doc->version)
        fprintf(file, "<?xml encoding=\"%s\"?>\n", doc->encoding);
    else if (!doc->encoding)
        fprintf(file, "<?xml version=\"%s\"?>\n", doc->version);
    else
        fprintf(file, "<?xml version=\"%s\" encoding=\"%s\"?>\n", doc->version,
            doc->encoding);
}

int xmlSaveFormatFile(const char *filename, xmlDocPtr doc, int format)
{
    FILE *file = NULL;
    xmlNodePtr root = NULL;

    if (!filename || !doc)
        return FAILURE;
    root = xmlDocGetRootElement(doc);
    if (!root)
        return FAILURE;
    file = fopen(filename, "w");
    if (!file)
        return FAILURE;
    write_doc(file, doc);
    write_file(file, root, format);
    fclose(file);
    return SUCCESS;
}

int xmlSaveFile(const char *filename, xmlDocPtr doc)
{
    return xmlSaveFormatFile(filename, doc, 0);
}
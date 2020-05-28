/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlSave.c
*/

#include <stdio.h>

#include "libxml3.h"

void write_info(FILE *file, xmlNodePtr child, int depth, int format)
{
    if (child->children)
        write_children(file, child->children, depth + 1, format);
    else {
        if (child->content)
            fprintf(file, "%*s<%s>%s</%s>\n", depth * format, "",
                child->parent->name, child->parent->content,
                child->parent->name);
        else
            fprintf(file, "%*s<%s></%s>\n", depth * format, "",
                child->parent->name, child->parent->name);
    }
}

void write_children(FILE *file, xmlNodePtr node, int depth, int format)
{
    if (!node)
        return;
    if (node->children) {
        fprintf(file, "%*s<%s>\n", depth * format, "", node->name);
        for (xmlNodePtr child = node->children; child; child = child->next) {
            write_info(file, child, depth, format);
        }
        fprintf(file, "%*s</%s>\n", depth * format, "", node->name);
    }
}

void write_file(FILE *file, xmlNodePtr root, int format)
{
    int depth = 0;

    if (root->name)
        fprintf(file, "%*s<%s>\n", depth * format, "", root->name);
    if (root->children) {
        depth = 1;
        for (xmlNodePtr child = root->children; child; child = child->next) {
            fprintf(file, "%*s<%s>\n", depth * format, "", root->name);
            write_children(file, child->children, depth + 1, format);
            fprintf(file, "%*s</%s>\n", depth * format, "", root->name);
        }
    }
    if (root->name)
        fprintf(file, "%*s</%s>\n", depth * format, "", root->name);
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
    return SUCCESS;
}

int xmlSaveFile(const char *filename, xmlDocPtr doc)
{
    return xmlSaveFormatFile(filename, doc, 0);
}
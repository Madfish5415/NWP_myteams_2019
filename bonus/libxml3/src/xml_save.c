/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlSave.c
*/

#include <stdio.h>

#include "libxml3.h"

void write_children(FILE *file, xml_node_ptr node, int depth, int format)
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
        for (xml_node_ptr chld = node->children; chld; chld = chld->next) {
            write_children(file, chld, depth + 1, format);
        }
    }
    fprintf(file, "%*s</%s>\n", depth * format, "", node->name);
}

void write_file(FILE *file, xml_node_ptr root, int format)
{
    int depth = 0;

    if (root->name)
        fprintf(file, "%*s<%s>\n", depth * format, "", root->name);
    if (root->children) {
        for (xml_node_ptr chld = root->children; chld; chld = chld->next) {
            write_children(file, chld, depth + 1, format);
        }
    }
    if (root->name)
        fprintf(file, "%*s</%s>", depth * format, "", root->name);
}

void write_doc(FILE *file, xml_doc_ptr dc)
{
    if (!dc->version && !dc->encoding)
        return;
    if (!dc->version)
        fprintf(file, "<?xml encoding=\"%s\"?>\n", dc->encoding);
    else if (!dc->encoding)
        fprintf(file, "<?xml version=\"%s\"?>\n", dc->version);
    else
        fprintf(file, "<?xml version=\"%s\" encoding=\"%s\"?>\n", dc->version,
                dc->encoding);
}

int save_format_file(const char *filename, xml_doc_ptr cur, int format)
{
    FILE *file = NULL;
    xml_node_ptr root = NULL;

    if (!filename || !cur)
        return FAILURE;
    root = doc_get_root_element(cur);
    if (!root)
        return FAILURE;
    file = fopen(filename, "w");
    if (!file)
        return FAILURE;
    write_doc(file, cur);
    write_file(file, root, format);
    fclose(file);
    return SUCCESS;
}

int save_file(const char *filename, xml_doc_ptr cur)
{
    return save_format_file(filename, cur, 0);
}
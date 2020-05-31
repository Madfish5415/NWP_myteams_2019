/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** libxml3.h
*/

#ifndef NWP_MYTEAMS_2019_LIBXML3_H
#define NWP_MYTEAMS_2019_LIBXML3_H

#define SUCCESS (0)
#define FAILURE (84)
#define BAD_CAST (char *)

#include <stdio.h>

typedef struct _xml_node {
    struct _xml_node *next;
    struct _xml_node *prev;
    struct _xml_node *parent;
    struct _xml_node *children;
    struct _xml_node *last;
    char *content;
    char *name;
} xml_node;

typedef xml_node *xml_node_ptr;

typedef struct _xml_doc {
    char *name;
    struct _xml_node *children;
    char *version;
    char *encoding;
} xml_doc;

typedef xml_doc *xml_doc_ptr;

char *node_get_content(xml_node_ptr cur);
xml_node_ptr node_set_content(xml_node_ptr cur, const char *content);

xml_node_ptr doc_get_root_element(xml_doc_ptr doc);
xml_node_ptr doc_set_root_element(xml_doc_ptr doc, xml_node_ptr root);

xml_node_ptr new_node(const char *name);
xml_node_ptr new_text(const char *name, const char *content);
xml_node_ptr new_text_child(
    xml_node_ptr parent, const char *name, const char *content);
xml_doc_ptr new_doc(const char *version);

xml_node_ptr add_child(xml_node_ptr parent, xml_node_ptr cur);
xml_node_ptr add_next_sibling(xml_node_ptr cur, xml_node_ptr elem);
xml_node_ptr add_prev_sibling(xml_node_ptr cur, xml_node_ptr elem);
xml_node_ptr add_sibling(xml_node_ptr cur, xml_node_ptr elem);

xml_doc_ptr parse_file(const char *filename);

void unlink_node(xml_node_ptr cur);

void free_node(xml_node_ptr cur);
void free_doc(xml_doc_ptr doc);

int save_file(const char *filename, xml_doc_ptr cur);
int save_format_file(const char *filename, xml_doc_ptr cur, int format);

#endif // NWP_MYTEAMS_2019_LIBXML3_H

/*
** EPITECH PROJECT, 2020
** libxml3
** File description:
** tree.c
*/

#include <stdlib.h>

#include "libxml3.h"
#include "parse.h"

static void addBranch(xml_node_ptr parent, char *str);

static void addDeeper(xml_node_ptr parent, char *str, char *open)
{
    xml_node_ptr node = NULL;
    char *close = NULL;

    close = getCloseBalise(str);
    node = add_child(parent, new_node(open));
    if (close == NULL)
        addBranch(node, getnextline(str));
    else addBranch(parent, getnextline(str));
    if (close) free(close);
}

static void addBranch(xml_node_ptr parent, char *str)
{
    char *open = getOpenBalise(str);
    char *content = NULL;

    if (!open) {
        if (parent->parent == NULL) return;
        else return addBranch(parent->parent, getnextline(str));
    }
    content = getBaliseContent(str);

    if (content != NULL) {
        new_text_child(parent, open, content);
        addBranch(parent, getnextline(str));
    } else {
        addDeeper(parent, str, open);
    }
    free(open);
    if (content) free(content);
}

void createTree(char *str, xml_doc_ptr doc)
{
    char *open = NULL;
    char *close = NULL;
    char *content = NULL;

    if (!str) return;
    open = getOpenBalise(str);
    content = getBaliseContent(str);
    close = getCloseBalise(str);
    if (content != NULL) {
        doc->children = new_text(open, content);
    } else {
        doc->children = new_node(open);
        if (!close)
            addBranch(doc->children, getnextline(str));
    }
    if (open) free(open);
    if (content) free(content);
    if (close) free(close);
}

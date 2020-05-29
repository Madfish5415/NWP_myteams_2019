/*
** EPITECH PROJECT, 2020
** libxml3
** File description:
** tree.c
*/

#include <stdlib.h>

#include "libxml3.h"
#include "parse.h"

static void addBranch(xmlNodePtr parent, char *str);

static void addDeeper(xmlNodePtr parent, char *str, char *open)
{
    xmlNodePtr node = NULL;
    char *close = NULL;

    close = getCloseBalise(str);
    node = xmlAddChild(parent, xmlNewNode(open));
    if (close == NULL)
        addBranch(node, getnextline(str));
    else addBranch(parent, getnextline(str));
    if (close) free(close);
}

static void addBranch(xmlNodePtr parent, char *str)
{
    char *open = getOpenBalise(str);
    char *content = NULL;

    if (!open) {
        if (parent->parent == NULL) return;
        else return addBranch(parent->parent, getnextline(str));
    }
    content = getBaliseContent(str);

    if (content != NULL) {
        xmlNewTextChild(parent, open, content);
        addBranch(parent, getnextline(str));
    } else {
        addDeeper(parent, str, open);
    }
    free(open);
    if (content) free(content);
}

void createTree(char *str, xmlDocPtr doc)
{
    char *open = NULL;
    char *close = NULL;
    char *content = NULL;

    if (!str) return;
    open = getOpenBalise(str);
    content = getBaliseContent(str);
    close = getCloseBalise(str);
    if (content != NULL) {
        doc->children = xmlNewText(open, content);
    } else {
        doc->children = xmlNewNode(open);
        if (!close)
            addBranch(doc->children, getnextline(str));
    }
    if (open) free(open);
    if (content) free(content);
    if (close) free(close);
}

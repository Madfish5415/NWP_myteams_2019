/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** libxml3.h
*/

#ifndef NWP_MYTEAMS_2019_LIBXML3_H
#define NWP_MYTEAMS_2019_LIBXML3_H

#define BAD_CAST (char *)

typedef struct _xmlNode {
    struct _xmlNode *next;
    struct _xmlNode *prev;
    struct _xmlNode *parent;
    struct _xmlNode *children;
    char *content;
    char *name;
} xmlNode;

typedef xmlNode *xmlNodePtr;

typedef struct _xmlDoc {
    char *name;
    struct _xmlNode *children;
    char *version;
    char *encoding;
} xmlDoc;

typedef xmlDoc *xmlDocPtr;

char *xmlNodeGetContent(xmlNodePtr cur);
xmlNodePtr xmlNodeSetContent(xmlNodePtr cur, const char *content);

xmlNodePtr xmlDocGetRootElement(xmlDocPtr doc);
xmlNodePtr xmlDocSetRootElement(xmlDocPtr doc, xmlNodePtr root);

xmlNodePtr xmlNewNode(const char *name);

xmlNodePtr xmlNewText(const char *content);
xmlNodePtr xmlNewTextChild(
    xmlNodePtr parent, const char *name, const char *content);

xmlNodePtr xmlAddChild(xmlNodePtr parent, xmlNodePtr cur);

xmlNodePtr xmlAddPrevSibling(xmlNodePtr cur, xmlNodePtr elem);
xmlNodePtr xmlAddSibling(xmlNodePtr cur, xmlNodePtr elem);

xmlDocPtr xmlNewDoc(const char *version);

xmlDocPtr xmlParseFile(const char *filename);

void xmlUnlinkNode(xmlNodePtr cur);
void xmlFreeNode(xmlNodePtr cur);

int xmlSaveFile(const char *filename, xmlDocPtr cur);
int xmlSaveFormatFile(const char *filename, xmlDocPtr cur, int format);

#endif // NWP_MYTEAMS_2019_LIBXML3_H

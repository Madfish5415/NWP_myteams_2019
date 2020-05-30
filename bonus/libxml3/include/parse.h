/*
** EPITECH PROJECT, 2020
** libxml3
** File description:
** parse.h
*/

#ifndef LIBXML3_PARSE_H
#define LIBXML3_PARSE_H

#include "libxml3.h"

#include <stdbool.h>

char *readFile(const char *filename);

void setParams(char *content, xmlDocPtr doc);

char *getRootElem(char *content);

void createTree(char *content, xmlDocPtr doc);

char *getOpenBalise(char *string);
char *getCloseBalise(char *string);
char *getBaliseContent(char *string);

char *getnextline(char *str);

#endif // LIBXML3_PARSE_H

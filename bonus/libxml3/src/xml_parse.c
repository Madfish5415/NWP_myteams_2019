/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xmlParse.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libxml3.h"
#include "parse.h"

char *readFile(const char *filename)
{
    FILE *file;
    char *line = NULL;
    char *result = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(filename, "r");
    if (file == NULL)
        return NULL;
    while ((read = getline(&line, &len, file)) != -1) {
        if (!result) {
            result = malloc(sizeof(char) * len);
            memset(result, '\0', len);
        } else
            result = realloc(result, strlen(result) + len);
        strcat(result, line);
    }
    if (line) free(line);
    fclose(file);
    return result;
}

xml_doc_ptr parse_file(const char *filename)
{
    xml_doc_ptr doc = NULL;
    char *content = NULL;

    if (filename == NULL) return NULL;
    content = readFile(filename);
    if (content == NULL) return NULL;
    if ((doc = new_doc(NULL)) == NULL) return NULL;
    setParams(content, doc);
    createTree(getRootElem(content), doc);
    free(content);
    return doc;
}

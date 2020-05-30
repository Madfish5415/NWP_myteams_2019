/*
** EPITECH PROJECT, 2020
** libxml3
** File description:
** getnextline.c
*/

#include <stdlib.h>

char *getnextline(char *str)
{
    int len = 0;

    if (!str) return NULL;
    for (int i = 0; str[i] && str[i] != '\n'; i++, len++);
    if (str[len] != '\0')
        return &str[len + 1];
    return NULL;
}
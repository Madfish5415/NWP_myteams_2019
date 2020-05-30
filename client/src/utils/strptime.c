/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** strptime.c
*/

#include <stdlib.h>
#include <time.h>

#include "utils.h"

static void convert_hours(char **tab, struct tm *tm)
{
    if (!tab)
        return;
    tm->tm_hour = atoi(tab[0]);
    tm->tm_min = atoi(tab[1]);
    tm->tm_sec = atoi(tab[2]);
}

static void convert_days(char **tab, struct tm *tm)
{
    if (!tab)
        return;
    tm->tm_mday = atoi(tab[0]);
    tm->tm_mon = atoi(tab[1]) - 1;
    tm->tm_year = atoi(tab[2]) + 100;
}

time_t strptime(char *string)
{
    struct tm tm;
    char **tab = NULL;
    char **date = NULL;
    char **hours = NULL;

    if (!string)
        return (time_t) NULL;
    tab = split(string, " ");
    date = split(tab[0], "-");
    hours = split(tab[1], ":");
    convert_hours(hours, &tm);
    convert_days(date, &tm);
    return mktime(&tm);
}
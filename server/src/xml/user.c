/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.c
*/

#include <libxml/tree.h>
#include <time.h>
#include <uuid/uuid.h>

xmlNodePtr create_user(const char *username, const char *passwd)
{
    xmlNodePtr user;
    uuid_t uuid;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    char uuid_str[37];

    strftime(s, sizeof(s), "%c", tm);
    uuid_generate((unsigned char *)&uuid);
    uuid_unparse(uuid, uuid_str);

    user = xmlNewNode(NULL, BAD_CAST "user");

    xmlNewTextChild(user, NULL, BAD_CAST "uuid", BAD_CAST uuid_str);
    xmlNewTextChild(user, NULL, BAD_CAST "username", BAD_CAST username);
    xmlNewTextChild(user, NULL, BAD_CAST "password", BAD_CAST passwd);
    xmlNewTextChild(user, NULL, BAD_CAST "date", BAD_CAST s);
    xmlNewTextChild(user, NULL, BAD_CAST "connected", BAD_CAST "false");

    return user;
}
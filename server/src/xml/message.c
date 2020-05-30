/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message.c
*/

#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

#include "def.h"
#include "exception.h"
#include "libxml3.h"
#include "logging_server.h"
#include "xml.h"

xmlNodePtr message_create(
    const char *body, const char *creator)
{
    xmlNodePtr message;
    time_t t = time(NULL);
    struct tm *localt = localtime(&t);
    char time_str[TIME_SIZE];

    strftime(time_str, sizeof(time_str), "%d-%m-%y %H:%M:%S", localt);
    message = xmlNewNode(BAD_CAST "message");
    xmlNewTextChild(message, BAD_CAST "body", BAD_CAST body);
    xmlNewTextChild(message, BAD_CAST "date", BAD_CAST time_str);
    xmlNewTextChild(message, BAD_CAST "creator", BAD_CAST creator);

    return message;
}

xmlNodePtr message_thread_create(
    const char *body, const char *creator, const char *thread_uid)
{
    server_event_thread_new_message(thread_uid, creator, body);
    return message_create(body, creator);
}

xmlNodePtr message_discussion_create(
    const char *sender_id, const char *receiver_id, const char *body)
{
    server_event_private_message_sended(sender_id, receiver_id, body);
    return message_create(body, sender_id);
}

exception_t message_add(
    xmlNodePtr message, xmlDocPtr xml_tree, const char *thread_uid)
{
    exception_t exception = {NO_ERROR};
    xmlNodePtr thread = thread_get(xml_tree, thread_uid);

    if (!thread || !thread->children) {
        exception = new_exception(
            OUT_OF_RANGE, "message_add (xml/message.c)", "Threads not found");
        return exception;
    }
    for (xmlNodePtr messages = thread->children; messages;
            messages = messages->next) {
        if (strcmp((char *)messages->name, "messages") == 0) {
            xmlAddChild(messages, message);
            return exception;
        }
    }
    exception = new_exception(
        OUT_OF_RANGE, "message_add (xml/message.c)", "Threads not found");
    return exception;
}
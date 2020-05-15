/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help.h
*/

#ifndef NWP_MYTEAMS_2019_HELP_H
#define NWP_MYTEAMS_2019_HELP_H

static const char *HELP_STRING = "• /help : show help\n"
    "• /login [“username”] : set the username used by client\n"
    "• /logout : disconnect the client from the server\n"
    "• /users : get the list of all users that exist on the domain\n"
    "• /user [“user_uuid”] : get information about a user\n"
    "• /send [“user_uuid”] [“message_body”] : send a message to a user\n"
    "• /messages [“user_uuid”] : list all messages exchange with an user\n"
    "• /subscribe [“team_uuid”] : subscribe to the event of a team and its sub directories (enable receptionof all events from a team)\n"
    "• /subscribed ?[“team_uuid”] : list all subscribed teams or list all users subscribed to a team\n"
    "• /unsubscribe [“team_uuid”] : unsubscribe from a team\n"
    "• /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : use specify a context team/channel/thread\n"
    "• /create : based on what is being used create the sub resource\n"
    "• /list : based on what is being used list all the sub resources \n"
    "• /info : based on what is being used list the current \n";

#endif // NWP_MYTEAMS_2019_HELP_H

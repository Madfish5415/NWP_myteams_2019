/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_functions.h
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_FUNCTIONS_H
#define NWP_MYTEAMS_2019_CLIENT_FUNCTIONS_H

void cli_event_loggedin(char **tab);
void cli_event_loggedout(char **tab);
void cli_event_private_message_received(char **tab);
void cli_event_thread_message_received(char **tab);
void cli_event_team_created(char **tab);
void cli_event_channel_created(char **tab);
void cli_event_thread_created(char **tab);
void cli_print_users(char **tab);
void cli_print_teams(char **tab);
void cli_team_print_channels(char **tab);
void cli_channel_print_threads(char **tab);
void cli_thread_print_replies(char **tab);
void cli_private_message_print_messages(char **tab);
void cli_error_unknown_team(char **tab);
void cli_error_unknown_channel(char **tab);
void cli_error_unknown_thread(char **tab);
void cli_error_unknown_user(char **tab);
void cli_error_unauthorized(char **tab);
void cli_error_already_exist(char **tab);
void cli_print_user(char **tab);
void cli_print_team(char **tab);
void cli_print_channel(char **tab);
void cli_print_thread(char **tab);
void cli_print_team_created(char **tab);
void cli_print_channel_created(char **tab);
void cli_print_thread_created(char **tab);
void cli_print_reply_created(char **tab);
void cli_print_subscribed(char **tab);
void cli_print_unsubscribed(char **tab);

#endif // NWP_MYTEAMS_2019_CLIENT_FUNCTIONS_H

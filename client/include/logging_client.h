#ifndef __LOGGING_CLIENT_H__
#define __LOGGING_CLIENT_H__

#include <stdint.h>
#include <time.h>

//! Handler called when a user connect to the server (you or someone else)
/*!
	\param user_id a character pointer corresponding to the universally unique id assigned to the currently logged in user
	\param user_name a character pointer corresponding to the user name.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_event_loggedin(char const *user_id, const char *user_name);

//! Handler called when a user disconnect from the server (you or someone else)
/*!
	\param user_id a character pointer corresponding to the universally unique id assigned to the currently logged out user
	\param user_name a character pointer corresponding to the user name.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_event_loggedout(char const *user_id, const char *user_name);

//! Handler called when a new private message is received
/*!
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who sended the message.
	\param message_body a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_event_private_message_received(char const *user_id, char const *message_body);

//! Handler called when a new reply is post in a thread
/*!
	\param team_id a character pointer corresponding to the universally unique id assigned to the team hosting the thread.
	\param thread_id a character pointer corresponding to the universally unique id assigned to the thread hosting the reply.
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who sended the message.
	\param message a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_event_thread_message_received(char const *team_id, char const *thread_id, char const *user_id, char const *message);

//! Handler called when a new team is created
/*!
	\param team_id a character pointer corresponding to the universally unique id assigned to the team.
	\param team_name a character pointer corresponding to the team's name.
	\param team_description a character pointer corresponding to the team's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_event_team_created(char const *team_id, char const *team_name, char const *team_description);

//! Handler called when a new channel is created
/*!
	\param channel_id a character pointer corresponding to the universally unique id assigned to the channel in the team.
	\param channel_name a character pointer corresponding to the channel's name.
	\param channel_description a character pointer corresponding to the channel's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_event_channel_created(char const *channel_id, char const *channel_name, char const *channel_description);


//! Handler called when a new thread is created
/*!
	\param thread_id a character pointer corresponding to the universally unique id assigned to the thread in the team.
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who created the thread.
	\param thread_timestamp an unsigned integer corresponding to the timestamp of the thread's creation.
	\param thread_title a character pointer corresponding to the thread title.
	\param thread_body a character pointer corresponding to the thread body.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_event_thread_created(char const *thread_id, char const *user_id, time_t thread_timestamp, char const *thread_title, char const *thread_body);

//! Handler called when the user ask for the users list (/list CLI command), used in a loop over each team
/*!
	\param user_id a character pointer corresponding to the universally unique id assigned to the user.
	\param user_name a character pointer corresponding to the user's name.
	\param user_status an integer corresponding to the user status (0 = not connected; 1 = connected).
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_print_users(char const *user_id, char const *user_name, int user_status);

//! Handler called when the user ask for the team list (/list CLI command), used in a loop over each team
/*!
	\param team_id a character pointer corresponding to the universally unique id assigned to the team.
	\param team_name a character pointer corresponding to the team's name.
	\param team_description a character pointer corresponding to the team's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_print_teams(char const *team_id, char const *team_name, char const *team_description);


//! Handler called when the user select a specific team to be in (/list CLI command), used in a loop over each channel
/*!
	\param channel_id a character pointer corresponding to the universally unique id assigned to the channel in the team.
	\param channel_name a character pointer corresponding to the channel's name.
	\param channel_description a character pointer corresponding to the channel's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_team_print_channels(char const *channel_id, char const *channel_name, char const *channel_description);

//! Handler called when the user select a specific channel to be in (/list CLI command), used in a loop over each thread
/*!
	\param thread_id a character pointer corresponding to the universally unique id assigned to the thread in the team.
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who created the thread.
	\param thread_timestamp an unsigned integer corresponding to the timestamp of the thread's creation.
	\param thread_title a character pointer corresponding to the thread title.
	\param thread_body a character pointer corresponding to the thread body.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_channel_print_threads(char const *thread_id, char const *user_id, time_t thread_timestamp, char const *thread_title, char const *thread_body);

//! Handler called when the user ask for a specific thread (/list CLI command), used in a loop over each reply
/*!
	\param thread_id a character pointer corresponding to the universally unique id assigned to the thread in the channel.
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who created the thread.
	\param reply_timestamp an unsigned integer corresponding to the timestamp of the reply.
	\param reply_body a character pointer corresponding to the reply.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_thread_print_replies(char const *thread_id, char const *user_id, time_t reply_timestamp, char const *reply_body);

//! Handler called when the user ask for a specific private discussion (/messages CLI command), used in a loop over each message
/*!
	\param sender_id a character pointer corresponding to the universally unique id assigned to the user sending the message
	\param timestamp an unsigned integer corresponding to the timestamp of the message.
	\param message a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_private_message_print_messages(char const *sender_id, time_t timestamp, char const *message);

//! Handler called when the user ask for an unknown specific team
/*!
	\param team_id an unsigned integer corresponding to the WRONG team identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_team(char const *team_id);

//! Handler called when the user ask for an unknown specific channel
/*!
	\param channel_id an unsigned integer corresponding to the WRONG channel identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_channel(char const *channel_id);

//! Handler called when the user ask for an unknown specific thread
/*!
	\param thread_id an unsigned integer corresponding to the WRONG thread identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_thread(char const *thread_id);

//! Handler called when the user want to chat with an unknown user (/messages and /send CLI command)
/*!
	\param user_id an unsigned integer corresponding to the WRONG user identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_user(char const *user_id);

//! Handler called when the user want to perform an action that is unauthorized (not login/subscribed)
/*!
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_error_unauthorized(void);

//! Handler called when the user want to perform an action that was refused by the server because the resource was already existing
/*!
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_error_already_exist(void);

//! Handler called when the user ask for a user in particular (/user or /info CLI command)
/*!
	\param user_id a character pointer corresponding to the universally unique id assigned to the user.
	\param user_name a character pointer corresponding to the user's name.
	\param user_status an integer corresponding to the user status (0 = not connected; 1 = connected).
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_user(char const *user_id, char const *user_name, int user_status);

//! Handler called when the user ask for a team in particular (/info CLI command)
/*!
	\param team_id a character pointer corresponding to the universally unique id assigned to the team.
	\param team_name a character pointer corresponding to the team's name.
	\param team_description a character pointer corresponding to the team's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_team(char const *team_id, char const *team_name, char const *team_description);


//! Handler called when the user ask for a channel in particular (/info CLI command)
/*!
	\param channel_id a character pointer corresponding to the universally unique id assigned to the channel.
	\param channel_name a character pointer corresponding to the channel's name.
	\param channel_description a character pointer corresponding to the channel's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_channel(char const *channel_id, char const *channel_name, char const *channel_description);


//! Handler called when the user ask for a thread in particular (/info CLI command)
/*!
	\param thread_id a character pointer corresponding to the universally unique id assigned to the thread.
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who created the thread.
	\param thread_timestamp an unsigned integer corresponding to the timestamp of the thread's creation.
	\param thread_title a character pointer corresponding to the thread title.
	\param thread_body a character pointer corresponding to the thread body.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_thread(char const *thread_id, char const *user_id, time_t thread_timestamp, char const *thread_title, char const *thread_body);


//! Handler called when the user create a team (/create CLI command)
/*!
	\param team_id a character pointer corresponding to the universally unique id assigned to the team.
	\param team_name a character pointer corresponding to the team's name.
	\param team_description a character pointer corresponding to the team's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_team_created(char const *team_id, char const *team_name, char const *team_description);


//! Handler called when the user create a channel (/create CLI command)
/*!
	\param channel_id a character pointer corresponding to the universally unique id assigned to the channel.
	\param channel_name a character pointer corresponding to the channel's name.
	\param channel_description a character pointer corresponding to the channel's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_channel_created(char const *channel_id, char const *channel_name, char const *channel_description);


//! Handler called when the user create a thread (/create CLI command)
/*!
	\param thread_id a character pointer corresponding to the universally unique id assigned to the thread.
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who created the thread.
	\param thread_timestamp an unsigned integer corresponding to the timestamp of the thread's creation.
	\param thread_title a character pointer corresponding to the thread title.
	\param thread_body a character pointer corresponding to the thread body.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_thread_created(char const *thread_id, char const *user_id, time_t thread_timestamp, char const *thread_title, char const *thread_body);


//! Handler called when the user create a reply (/create CLI command)
/*!
	\param thread_id a character pointer corresponding to the universally unique id assigned to the thread in the channel.
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who created the thread.
	\param reply_timestamp an unsigned integer corresponding to the timestamp of the reply.
	\param reply_body a character pointer corresponding to the reply.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_reply_created(char const *thread_id, char const *user_id, time_t reply_timestamp, char const *reply_body);


//! Handler called when the user create a reply (/subscribe CLI command)
/*!
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who subscribed;
	\param team_id a character pointer corresponding to the universally unique id assigned to the team the user subscribed to.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_subscribed(char const *user_id, char const *team_id);


//! Handler called when the user create a reply (/unsubscribe CLI command)
/*!
	\param user_id a character pointer corresponding to the universally unique id assigned to the user who unsubscribed;
	\param team_id a character pointer corresponding to the universally unique id assigned to the team the user unsubscribed from.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately
*/
int client_print_unsubscribed(char const *user_id, char const *team_id);

#endif /* __LOGGING_CLIENT_H__ */

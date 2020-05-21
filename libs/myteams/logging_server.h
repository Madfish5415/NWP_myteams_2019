#ifndef __LOGGING_SERVER_H__
#define __LOGGING_SERVER_H__

#include <stdint.h>
#include <time.h>

//! Handler called when a new team is created
/*!
	\param team_id a character pointer corresponding to the universally unique identifier corresponding to the newly created team.
	\param team_name a character pointer corresponding to the name of the newly created team.
	\param user_id a character pointer corresponding to the name of the user who created the team.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_team_created(char const *team_id, char const *team_name, char const *user_id);

//! Handler called when a channel is created
/*!
	\param team_id a character pointer corresponding to the universally unique identifier corresponding to the team hosting the channel.
	\param channel_id a character pointer corresponding to the universally unique identifier corresponding to the newly created channel.
	\param channel_name a character pointer corresponding to the name of the newly created channel.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_channel_created(char const *team_id, char const *channel_id, char const *channel_name);

//! Handler called when a thread is created
/*!
	\param channel_id a character pointer corresponding to the universally unique identifier corresponding to the channel hosting the thread.
	\param thread_id a character pointer corresponding to the universally unique identifier corresponding to the newly created thread.
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to of the user posting the message.
	\param message a character pointer corresponding to the thread's content.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_thread_created(char const *channel_id, char const *thread_id, char const *user_id, char const *message);

//! Handler called when a message is post in a thread
/*!
	\param thread_id a character pointer corresponding to the universally unique identifier corresponding to the thread hosting the message.
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to of the user posting the message.
	\param message a character pointer corresponding to the message's content.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_thread_new_message(char const *thread_id, char const *user_id, char const *message);

//! Handler called when a user join a team
/*!
	\param team_id a character pointer corresponding to the universally unique identifier corresponding to the corresponding team.
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to of the user joining the team.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_user_join_a_team(char const *team_id, char const *user_id);

//! Handler called when a user leave a team
/*!
	\param team_id a character pointer corresponding to the universally unique identifier corresponding to the corresponding team.
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to the user leaving the team.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_user_leave_a_team(char const *team_id, char const *user_id);

//! Handler called when a user is created
/*!
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to the newly created user.
	\param user_name a character pointer corresponding to the name of the newly created user.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_user_created(char const *user_id, char const *user_name);

//! Handler called when a user is reloaded (on server startup)
/*!
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to the newly created user.
	\param user_name a character pointer corresponding to the name of the newly created user.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_user_loaded(char const *user_id, char const *user_name);

//! Handler called when a user is logging in
/*!
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to the newly logged user.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_user_logged_in(char const *user_id);

//! Handler called when a user is logging out
/*!
	\param user_id a character pointer corresponding to the universally unique identifier corresponding to the newly logged user.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_user_logged_out(char const *user_id);

//! Handler called when a user send a private message to an other
/*!
	\param sender_id a character pointer corresponding to the universally unique identifier corresponding to the user sending the message.
	\param receiver_id a character pointer corresponding to the universally unique identifier corresponding to the user receiving the message.
	\param message a character pointer corresponding to the message's content.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int server_event_private_message_sended(char const *sender_id, char const *receiver_id, char const *message);



#endif /* __LOGGING_SERVER_H__ */

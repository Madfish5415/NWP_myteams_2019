/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** response.h
*/

#ifndef NWP_MYTEAMS_2019_RESPONSE_H
#define NWP_MYTEAMS_2019_RESPONSE_H

static const char *const RESPONSE_220 = "220 Connected.\r\n";
static const char *const RESPONSE_230 =
    "230\r\n"; // User logged in: user_id, user_name
static const char *const RESPONSE_231 =
    "231\r\n"; // User logged out: user_id, user_name
static const char *const RESPONSE_232 =
    "232\r\n"; // Event private message received: user_id, message_body
static const char *const RESPONSE_233 =
    "233\r\n"; // Event thread message received: team_id, thread_id, user_id,
// message
static const char *const RESPONSE_234 =
    "234\r\n"; // Event team created: team_id, team_name, team_description
static const char *const RESPONSE_235 =
    "235\r\n"; // Event channel created: channel_id, channel_name,
// channel_description
static const char *const RESPONSE_236 =
    "236\r\n"; // Event thread created: thread_id, user_id, thread_timestamp,
// thread_title, thread_body
static const char *const RESPONSE_240 =
    "240\r\n"; // Print users: user_id, user_name, user_status
static const char *const RESPONSE_241 =
    "241\r\n"; // Print teams: team_id, team_name, team_description
static const char *const RESPONSE_242 =
    "242\r\n"; // Print user: user_id, user_name, user_status
static const char *const RESPONSE_243 =
    "243\r\n"; // Print team: team_id, team_name, team_description
static const char *const RESPONSE_244 =
    "244\r\n"; // Print channel: channel_id, channel_name, channel_description
static const char *const RESPONSE_245 =
    "245\r\n"; // Print thread: thread_id, user_id, thread_timestamp,
// thread_title, thread_body
static const char *const RESPONSE_246 =
    "246\r\n"; // Print team created: team_id, team_name, team_description
static const char *const RESPONSE_247 =
    "247\r\n"; // Print channel created: channel_id, channel_name,
// channel_description
static const char *const RESPONSE_248 =
    "248\r\n"; // Print thread created: thread_id, user_id, thread_timestamp,
// thread_title, thread_body
static const char *const RESPONSE_249 =
    "249\r\n"; // Print reply created: thread_id, user_id, reply_timestamp,
// reply_body
static const char *const RESPONSE_250 =
    "250\r\n"; // Print subscribed: user_id, team_id
static const char *const RESPONSE_251 =
    "251\r\n"; // Print unsubscribed: user_id, team_id
static const char *const RESPONSE_252 =
    "252\r\n"; // Team print channels: channel_id, channel_name,
// channel_description
static const char *const RESPONSE_253 =
    "253\r\n"; // Channel print threads: thread_id, user_id, thread_timestamp,
// thread_title, thread_body
static const char *const RESPONSE_254 =
    "254\r\n"; // Thread print replies: thread_id, user_id, reply_timestamp,
// reply_body
static const char *const RESPONSE_255 =
    "255\r\n"; // Private message print messages: sender_id, timestamp, message

/* ERROR CODE */
static const char *const RESPONSE_501 = "501\r\n"; // Error unknown user:
// user_id
static const char *const RESPONSE_502 = "502\r\n"; // Error unknown team:
// team_id
static const char *const RESPONSE_503 =
    "503\r\n"; // Error unknown channel: channel_id
static const char *const RESPONSE_504 =
    "504\r\n"; // Error unknown thread: thread_id
static const char *const RESPONSE_505 = "505\r\n"; // Error unauthorized: (void)
static const char *const RESPONSE_506 = "506\r\n"; // Error already exist:
// (void)

#endif // NWP_MYTEAMS_2019_RESPONSE_H

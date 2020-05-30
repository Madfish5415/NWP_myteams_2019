# RFC Documentation
RFC documentation created for the my_Teams project by Lucas Mathieux, Lucas Fabreguettes and Mattéo Fauchon

## Event and Log
Code            |Signification                      | Args number   | Arguments 
----------------|-----------------------------------|---------------|-----------
230             |User logged in                     |2              |user_id, user_name
231             |User logged out                    |2              |user_id, user_name
232             |Event private message receive      |2              |user_id, message_body
233             |Event thread message receive       |4              |team_id, thread_id, user_id, message
234             |Event team created                 |3              |team_id, team_name, team_description
235             |Event channel created              |3              |channel_id, channel_name, channel_description
236             |Event thread created               |5              |thread_id, user_id, thread_timestamp, thread_title, thread_body

## Print informations
Code            |Signification                      | Args number   | Arguments
----------------|-----------------------------------|---------------|-----------
240             |Print users                        |3              |user_id, user_name, user_status
241             |Print teams                        |3              |team_id, team_name, team_description
242             |Print user                         |3              |user_id, user_name, user_status
243             |Print team                         |3              |team_id, team_name, team_description
244             |Print channel                      |3              |channel_id, channel_name, channel_description
245             |Print thread                       |5              |thread_id, user_id, thread_timestamp, thread_title, thread_body
246             |Print team created                 |3              |team_id, team_name, team_description
247             |Print channel created              |3              |channel_id, channel_name, channel_description
248             |Print thread created               |5              |thread_id, user_id, thread_timestamp, thread_title, thread_body
249             |Print reply created                |4              |thread_id, user_id, reply_timestamp, reply_body
250             |Print subscribed                   |2              |user_id, team_id
251             |Print unsubscribed                 |2              |user_id, team_id
252             |Team print channels                |3              |channel_id, channel_name, channel_description
253             |Channel print threads              |5              |thread_id, user_id, thread_timestamp, thread_title, thread_body
254             |Thread print replies               |4              |thread_id, user_id, reply_timestamp, reply_body
255             |Private message print messages     |3              |sender_id, timestamp, message

## Error
Code            |Signification                      | Args number   | Arguments
----------------|-----------------------------------|---------------|-----------
501             |Unknown user                       |1              |user_id
502             |Unknown team                       |1              |team_id
503             |Unknown channel                    |1              |channel_id
504             |Unknown thread                     |1              |thread_id
505             |Command unauthorized               |0              |
506             |Already exist                 |0              |
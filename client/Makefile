##
## EPITECH PROJECT, 2019
## NWP_myteams_2019
## File description:
## Makefile
##

NAME				=		myteams_cli
TEST_NAME			=		tests/unit_tests
TEST_SH_NAME		=		tests/tests.sh

COV_DIR				=		obj
INCL_DIR			=		include
OBJ_DIR				=		obj
SRC_DIR				=		src
TEST_DIR			=		tests

AR					=		ar rcs
CC					=		gcc
RM					=		rm -rf

MAIN_SRC			=		main.c

PROJ_SRC			=		help.c													\
							utils/split.c											\
							utils/strptime.c										\
							arguments/flag.c										\
							arguments/parser.c										\
							arguments/port.c										\
							error/exception.c										\
							error/check_missing_quote.c								\
							socket/socket_creation.c								\
							socket/socket_connection.c								\
							client/client_run.c										\
							client/client_init.c									\
							client/client_read_server.c								\
							client/client_clean.c									\
							client/client_execute_cmd.c								\
							client/client_format_string.c							\
							client/client_handle_fd.c								\
							client/client_handle_read.c								\
							client/client_handle_write.c							\
							client_functions/cli_event_loggedin.c					\
							client_functions/cli_event_loggedout.c					\
							client_functions/cli_event_private_message_received.c	\
							client_functions/cli_event_thread_message_received.c	\
							client_functions/cli_event_team_created.c				\
							client_functions/cli_event_channel_created.c			\
							client_functions/cli_event_thread_created.c				\
							client_functions/cli_print_users.c						\
							client_functions/cli_print_teams.c						\
							client_functions/cli_team_print_channels.c				\
							client_functions/cli_channel_print_threads.c			\
							client_functions/cli_thread_print_replies.c				\
							client_functions/cli_private_message_print_messages.c	\
							client_functions/cli_error_unknown_team.c				\
							client_functions/cli_error_unknown_channel.c			\
							client_functions/cli_error_unknown_thread.c				\
							client_functions/cli_error_unknown_user.c				\
							client_functions/cli_error_unauthorized.c				\
							client_functions/cli_error_already_exist.c				\
							client_functions/cli_print_user.c						\
							client_functions/cli_print_team.c						\
							client_functions/cli_print_channel.c					\
							client_functions/cli_print_thread.c						\
							client_functions/cli_print_team_created.c				\
							client_functions/cli_print_channel_created.c			\
							client_functions/cli_print_thread_created.c				\
							client_functions/cli_print_reply_created.c				\
							client_functions/cli_print_subscribed.c					\
							client_functions/cli_print_unsubscribed.c				\

TEST_SRC			=

CFLAGS				+=		-I $(INCL_DIR) -I ../libs/myteams/
CFLAGS				+=		-W -Wall -Wextra -Werror

LDLIBS				=		-luuid -L../libs/myteams -lmyteams

MAIN_OBJ			=		$(MAIN_SRC:%.c=$(OBJ_DIR)/%.o)

PROJ_OBJ			=		$(PROJ_SRC:%.c=$(OBJ_DIR)/%.o)

TEST_OBJ			=		$(TEST_SRC:%.c=$(OBJ_DIR)/%.o)

TEST_COV			=		$(PROJ_SRC:%.c=$(COV_DIR)/%.gcda)	\
							$(PROJ_SRC:%.c=$(COV_DIR)/%.gcno)	\
							$(TEST_SRC:%.c=$(COV_DIR)/%.gcda)	\
							$(TEST_SRC:%.c=$(COV_DIR)/%.gcno)	\

MAKEFLAGS			+=		--silent

NO_COLOR			=		\e[0;0m
GREEN_COLOR			=		\e[0;32m
RED_COLOR			=		\e[0;31m
GREEN_B_COLOR		=		\e[1;32m
RED_B_COLOR			=		\e[1;31m
YELLOW_B_COLOR		=		\e[1;33m

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(OBJ_DIR)/%.o:		$(TEST_DIR)/%.c
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(NAME):			$(MAIN_OBJ) $(PROJ_OBJ)
					$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

all:				$(NAME)

clean:
					$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

sweet:				all clean

debug:				CFLAGS += -g3
debug:				all

debug_re:			CFLAGS += -g3
debug_re:			re

debug_sweet:		CFLAGS += -g3
debug_sweet:		sweet

$(TEST_NAME):		CFLAGS += -fprofile-arcs -ftest-coverage
$(TEST_NAME):		LDLIBS += -lgcov -lcriterion
$(TEST_NAME):		$(PROJ_OBJ) $(TEST_OBJ)
					if [ -d $(TEST_DIR) ]; then \
						$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
						&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; } \
					fi

tests_run:			$(TEST_NAME)
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Unit tests not found$(NO_COLOR)"; \
					else \
						./$(TEST_NAME) \
						&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

tests_clean:		clean
					$(RM) $(TEST_OBJ)
					$(RM) $(TEST_COV)

tests_fclean:		tests_clean
					$(RM) $(TEST_NAME)

tests_re:			tests_fclean tests_run

tests_sweet:		tests_run tests_clean

tests_sh:			re
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_SH_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Functional tests not found$(NO_COLOR)"; \
					else \
						sh $(TEST_SH_NAME) $(NAME) \
						&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

full:				all

full_clean:			clean tests_clean

full_fclean:		fclean tests_fclean

full_re:			full_fclean full

full_sweet:			full full_clean

.PHONY:				all clean fclean re sweet											\
					debug debug_re debug_sweet											\
					tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh	\
					full full_clean full_fclean full_re full_sweet						\

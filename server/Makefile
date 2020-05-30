##
## EPITECH PROJECT, 2019
## NWP_myteams_2019
## File description:
## Makefile
##

NAME				=		myteams_server
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
MAKE				= 		make
CD					= 		cd

MAIN_SRC			=		main.c

PROJ_SRC			=		arguments/flag.c					\
							arguments/parser.c					\
							arguments/port.c					\
							buffer/buffer_create.c				\
							buffer/buffer_delete.c				\
							buffer/buffer_read.c				\
							buffer/buffer_write.c				\
							client/client_connect.c				\
							client/client_disconnect.c			\
							client/client_execute.c				\
							client/client_read.c				\
							client/client_write.c				\
							commands/create/create_channel.c	\
							commands/create/create_nocontext.c	\
							commands/create/create_team.c		\
							commands/create/create_thread.c		\
							commands/info/info_channel.c		\
                            commands/info/info_nocontext.c		\
                            commands/info/info_team.c			\
                            commands/info/info_thread.c			\
                            commands/list/list_channel.c		\
                            commands/list/list_nocontext.c		\
                            commands/list/list_team.c			\
                            commands/list/list_thread.c			\
							commands/create.c					\
							commands/info.c						\
							commands/list.c						\
							commands/login.c					\
							commands/logout.c					\
							commands/messages.c					\
							commands/send.c						\
							commands/subscribe.c				\
							commands/subscribed.c				\
							commands/unknown.c					\
							commands/unsubscribe.c				\
							commands/use.c						\
							commands/user.c						\
							commands/users.c					\
							error/exception.c					\
							server/server_add.c					\
							server/server_create.c				\
							server/server_delete.c				\
							server/server_get.c					\
							server/server_handle_execute.c		\
							server/server_handle_read.c			\
							server/server_handle_write.c		\
							server/server_init.c				\
							server/server_remove.c				\
							server/server_run.c					\
							server/server_send.c				\
							user/user_authorize.c				\
							utils/split.c						\
							xml/belongs_to.c					\
							xml/channel.c						\
							xml/discussion.c					\
							xml/message.c						\
							xml/subscribe.c						\
							xml/team.c							\
							xml/thread.c						\
							xml/user.c							\
							help.c								\

TEST_SRC			=

CFLAGS				+=		-I $(INCL_DIR)
CFLAGS				+=		-W -Wall -Wextra -Werror
CFLAGS				+=		-I "../libs/myteams/"
CFLAGS				+=		-I "../bonus/libxml3/include/"

LDLIBS				+=		-luuid
LDLIBS				+=		-L../libs/myteams -lmyteams
LDLIBS				+=		-L../bonus/libxml3 -lxml3

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

all:				$(MAKE_LIBS) $(NAME)

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

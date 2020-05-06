##
## EPITECH PROJECT, 2019
## ${PROJECT_NAME}
## File description:
## Makefile
##

NAME			=		myteams_server
LIB_NAME		=		myteams_server.so
LIB_ST_NAME		=		myteams_server.a
TEST_NAME		=		tests/unit_tests

NO_COLOR		=		\e[0;0m
GREEN_COLOR		=		\e[0;32m
RED_COLOR		=		\e[0;31m
GREEN_B_COLOR	=		\e[1;32m
RED_B_COLOR		=		\e[1;31m

AR				=		ar rcs
CC				=		gcc
RM				=		rm -rf

MAIN_SRC		=		main.c

PROJ_SRC		=

TEST_SRC		=

MAIN_OBJ		=		$(MAIN_SRC:.c=.o)

PROJ_OBJ		=		$(PROJ_SRC:.c=.o)

TEST_OBJ		=		$(TEST_SRC:.c=.o)

TEST_COV		=		$(PROJ_SRC:.c=.gcda)	\
						$(PROJ_SRC:.c=.gcno)	\
						$(TEST_SRC:.c=.gcda)	\
						$(TEST_SRC:.c=.gcno)	\

INCL_DIR		=		"include/"
LIB_DIR			=		"lib/my/"
LIB_INCL_DIR	=		"include/"

CFLAGS			+=		-I $(INCL_DIR)
CFLAGS			+=		-I $(LIB_DIR)/$(LIB_INCL_DIR)
CFLAGS			+=		-W -Wall -Wextra

MAKEFLAGS		+=		--silent

%.o:			%.c
				$(CC) $(CFLAGS) -c -o $@ $< \
				&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
				|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

all:			$(NAME)

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean

debug:			CFLAGS += -g3
debug:			all

debug_re:		CFLAGS += -g3
debug_re:		re

debug_sweet:	CFLAGS += -g3
debug_sweet:	sweet

lib:			CFLAGS += -fPIC
lib:			LDFLAGS += -shared
lib:			$(PROJ_OBJ)
				$(CC) $(PROJ_OBJ) -o $(LIB_NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(LIB_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(LIB_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib_clean:
				$(RM) $(PROJ_OBJ)

lib_fclean:		lib_clean
				$(RM) $(LIB_NAME)

lib_re:			lib_fclean lib

lib_sweet:		lib lib_clean

lib_st:			$(PROJ_OBJ)
				$(AR) $(LIB_ST_NAME) $(PROJ_OBJ) \
				&& echo "$(GREEN_B_COLOR)$(LIB_ST_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(LIB_ST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib_st_clean:	lib_clean

lib_st_fclean:	lib_st_clean
				$(RM) $(LIB_ST_NAME)

lib_st_re:		lib_st_fclean lib_st

lib_st_sweet:	lib_st lib_st_clean

tests_run:		CFLAGS += -fprofile-arcs -ftest-coverage
tests_run:		LDLIBS += -lgcov -lcriterion
tests_run:		$(PROJ_OBJ) $(TEST_OBJ)
				$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }
				$(TEST_NAME) \
				&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; }

tests_clean:	clean
				$(RM) $(TEST_OBJ)
				$(RM) $(TEST_COV)

tests_fclean:	tests_clean
				$(RM) $(TEST_NAME)

tests_re:		tests_fclean tests_run

tests_sweet:	tests_run tests_clean

tests_sh:		sweet
				sh tests/tests.sh $(NAME) \
				&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; }

full:			all lib lib_st

full_clean:		clean lib_clean lib_st_clean tests_clean

full_fclean:	fclean lib_fclean lib_st_fclean tests_fclean

full_re:		re lib_re lib_st_re

full_sweet:		sweet lib_sweet lib_st_sweet

.PHONY:			all clean fclean re sweet											\
				debug debug_re debug_sweet											\
				lib lib_clean lib_fclean lib_re lib_sweet							\
				lib_st lib_st_clean lib_st_fclean lib_st_re lib_st_sweet			\
				tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh	\
				full full_clean full_fclean full_re full_sweet						\

##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile.
##

CD = cd
CP = cp
RM = rm -rf
MAKE = make

SERVER_DIR = ./server/
CLIENT_DIR = ./client/

SERVER_BIN = myteams_server
CLIENT_BIN = myteams_cli

all:
		$(CD) $(SERVER_DIR) && $(MAKE) all && $(CP) $(SERVER_BIN) ../
		$(CD) $(CLIENT_DIR) && $(MAKE) all && $(CP) $(CLIENT_BIN) ../

clean:
		$(CD) $(SERVER_DIR) && $(MAKE) clean
		$(CD) $(CLIENT_DIR) && $(MAKE) clean

fclean:
		$(CD) $(SERVER_DIR) && $(MAKE) fclean
		$(CD) $(CLIENT_DIR) && $(MAKE) fclean
		$(RM) $(SERVER_BIN)
		$(RM) $(CLIENT_BIN)

re:
		$(CD) $(SERVER_DIR) && $(MAKE) re && $(CP) $(SERVER_BIN) ../
		$(CD) $(CLIENT_DIR) && $(MAKE) re && $(CP) $(CLIENT_BIN) ../

sweet:
		$(CD) $(SERVER_DIR) && $(MAKE) sweet && $(CP) $(SERVER_BIN) ../
		$(CD) $(CLIENT_DIR) && $(MAKE) sweet && $(CP) $(CLIENT_BIN) ../

debug:
		$(CD) $(SERVER_DIR) && $(MAKE) debug && $(CP) $(SERVER_BIN) ../
		$(CD) $(CLIENT_DIR) && $(MAKE) debug && $(CP) $(CLIENT_BIN) ../

debug_re:
		$(CD) $(SERVER_DIR) && $(MAKE) debug_re && $(CP) $(SERVER_BIN) ../
		$(CD) $(CLIENT_DIR) && $(MAKE) debug_re && $(CP) $(CLIENT_BIN) ../

debug_sweet:
		$(CD) $(SERVER_DIR) && $(MAKE) debug_sweet && $(CP) $(SERVER_BIN) ../
		$(CD) $(CLIENT_DIR) && $(MAKE) debug_sweet && $(CP) $(CLIENT_BIN) ../

tests_run:
		$(CD) $(SERVER_DIR) && $(MAKE) tests_run
		$(CD) $(CLIENT_DIR) && $(MAKE) tests_run

tests_clean:
		$(CD) $(SERVER_DIR) && $(MAKE) tests_clean
		$(CD) $(CLIENT_DIR) && $(MAKE) tests_clean

tests_fclean:
		$(CD) $(SERVER_DIR) && $(MAKE) tests_fclean
		$(CD) $(CLIENT_DIR) && $(MAKE) tests_fclean

tests_re:
		$(CD) $(SERVER_DIR) && $(MAKE) tests_re
		$(CD) $(CLIENT_DIR) && $(MAKE) tests_re

tests_sweet:
		$(CD) $(SERVER_DIR) && $(MAKE) tests_sweet
		$(CD) $(CLIENT_DIR) && $(MAKE) tests_sweet

tests_sh:
		$(CD) $(SERVER_DIR) && $(MAKE) tests_sh
		$(CD) $(CLIENT_DIR) && $(MAKE) tests_sh

.PHONY:			all clean fclean re sweet											\
				debug debug_re debug_sweet											\
				tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh	\
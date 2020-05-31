/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_delete.c
*/

#include <unistd.h>

#include "cmd.h"
#include "libxml3.h"
#include "server.h"

static void deconnect_all(server_t *server)
{
    char *cmds[2] = {"/logout", NULL};

    if (!server->clients) return;
    for (int i = 0; server->clients[i]; i++)
        if (server->clients[i]->user[0] != '\0') {
            cmd_logout(server, server->clients[i], cmds);
        }
    for (int i = 0; server->clients[i]; i++) {
        close(server->clients[i]->socket);
        FD_CLR(server->clients[i]->socket, &server->master[READ_SET]);
        FD_CLR(server->clients[i]->socket, &server->master[WRITE_SET]);
        FD_CLR(server->clients[i]->socket, &server->master[EXCEPT_SET]);
        buffer_delete(server->clients[i]->write_queue);
        buffer_delete(server->clients[i]->read_queue);
        free(server->clients[i]->write_queue);
        free(server->clients[i]->read_queue);
        free(server->clients[i]);
    }
    free(server->clients);
}

void server_delete(server_t **server)
{
    deconnect_all((*server));
    close((*server)->socket);
    save_format_file(XML_FILENAME, (*server)->xml_tree, 2);
    free_doc((*server)->xml_tree);
    free((*server));
}
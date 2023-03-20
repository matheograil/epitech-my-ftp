/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** close_socket.c file.
*/

#include "core.h"

void close_socket(parameters_t *p, int i, int must_close)
{
    if (must_close == 1) {
        close(p->client_sockets[i]);
    }
    p->client_sockets[i] = 0;
    p->username_provided[i] = 0;
    p->client_logged_in[i] = 0;
    my_free(p->current_path[i]);
    p->current_path[i] = strdup(p->path);
    if (p->current_path[i] == NULL) {
        my_exit(84, "Malloc (current_path) failed\n", p);
    }
}

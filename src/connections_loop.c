/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** connections_loop.c file.
*/

#include "core.h"

void connections_loop(parameters_t *p, int i)
{
    char buffer[BUFFER_SIZE] = { 0 };

    p->command_processed = 0;
    if (read(p->client_sockets[i], buffer, BUFFER_SIZE) == -1) {
        close_socket(p, i, 1);
    } else {
        connections_loop_read(p, i, buffer);
    }
}

void connections_loop_read(parameters_t *p, int i, char *buffer)
{
    for (int j = 0; j < BUFFER_SIZE; j++) {
        if (buffer[j] == '\r' || buffer[j] == '\n') {
            buffer[j] = '\0';
        }
    }
    command_username(p, i, buffer);
    if (p->username_provided[i] == 1 && p->client_logged_in[i] == 0)
        command_password(p, i, buffer);
    if (p->client_logged_in[i] == 1 && p->username_provided[i] == 1) {
        command_pwd(p, i, buffer);
        command_cwd(p, i, buffer, "250");
        command_delete(p, i, buffer);
        command_list(p, i, buffer);
        command_cdup(p, i, buffer);
    }
    command_noop(p, i, buffer);
    command_help(p, i, buffer);
    command_quit(p, i, buffer);
    if (p->command_processed == 0)
        my_write(p->client_sockets[i], "530 Command not found\r\n");
}

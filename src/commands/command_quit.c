/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_quit.c file.
*/

#include "core.h"

void command_quit(parameters_t *p, int i, char *buffer)
{
    char *quit_cmd = "QUIT";

    if (strcmp(buffer, quit_cmd) != 0) {
        return;
    }
    my_write(p->client_sockets[i], "221 Goodbye\r\n");
    close_socket(p, i, 1);
    p->command_processed = 1;
}

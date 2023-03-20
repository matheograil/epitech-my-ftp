/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_noop.c file.
*/

#include "core.h"

void command_noop(parameters_t *p, int i, char *buffer)
{
    char *pwd_cmd = "NOOP";

    if (strcmp(buffer, pwd_cmd) != 0) {
        return;
    }
    my_write(p->client_sockets[i], "200 No operation performed\r\n");
    p->command_processed = 1;
}

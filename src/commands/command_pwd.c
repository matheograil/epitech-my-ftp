/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_pwd.c file.
*/

#include "core.h"

void command_pwd(parameters_t *p, int i, char *buffer)
{
    char *pwd_cmd = "PWD";

    if (strcmp(buffer, pwd_cmd) != 0) {
        return;
    }
    my_write(p->client_sockets[i], "257 ");
    my_write(p->client_sockets[i], p->current_path[i]);
    my_write(p->client_sockets[i], "\r\n");
    p->command_processed = 1;
}

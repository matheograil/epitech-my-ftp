/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_username.c file.
*/

#include "core.h"

void command_username(parameters_t *p, int i, char *buffer)
{
    char *prefix = "USER";
    char *username_cmd = "USER Anonymous";

    if (strncmp(buffer, prefix, strlen(prefix)) != 0) {
        return;
    }
    if (strcmp(buffer, username_cmd) == 0) {
        my_write(p->client_sockets[i], "331 User name okay, "
            "need password.\r\n");
        p->username_provided[i] = 1;
        p->client_logged_in[i] = 0;
    } else {
        my_write(p->client_sockets[i], "530 Invalid username\r\n");
    }
    p->command_processed = 1;
}

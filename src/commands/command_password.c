/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_password.c file.
*/

#include "core.h"

void command_password(parameters_t *p, int i, char *buffer)
{
    char *prefix = "PASS";
    char *password_cmd = "PASS ";

    if (strncmp(buffer, prefix, strlen(prefix)) != 0) {
        return;
    }
    if (strcmp(buffer, password_cmd) == 0) {
        my_write(p->client_sockets[i], "230 User logged in, proceed.\r\n");
        p->client_logged_in[i] = 1;
    } else {
        my_write(p->client_sockets[i], "530 Not logged in\r\n");
    }
    p->command_processed = 1;
}

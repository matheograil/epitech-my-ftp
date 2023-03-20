/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_cwd.c file.
*/

#include "core.h"

void command_cwd(parameters_t *p, int i, char *buffer, char *success_code)
{
    char *prefix = "CWD";
    char *dir_fp;

    if (strncmp(buffer, prefix, strlen(prefix)) != 0) {
        return;
    }
    dir_fp = full_path(p, i, buffer + strlen(prefix) + 1);
    if (dir_fp == NULL) {
        my_write(p->client_sockets[i], "550 Failed to change directory\r\n");
    } else {
        command_cwd_check(p, i, dir_fp, success_code);
        my_free(dir_fp);
    }
    p->command_processed = 1;
}

void command_cwd_check(parameters_t *p, int i, char *dir_fp, char *code)
{
    if (invalid_path(dir_fp, p) == 1 || is_file_or_directory(dir_fp) != 'd') {
        my_write(p->client_sockets[i], "550 Failed to change directory\r\n");
    } else {
        my_free(p->current_path[i]);
        p->current_path[i] = strdup(dir_fp);
        if (p->current_path[i] == NULL) {
            my_free(dir_fp);
            my_exit(84, "Malloc (current_path) failed\n", p);
        }
        my_write(p->client_sockets[i], code);
        my_write(p->client_sockets[i], " Directory changed.\r\n");
    }
}

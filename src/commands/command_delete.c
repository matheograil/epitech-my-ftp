/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_delete.c file.
*/

#include "core.h"

void command_delete(parameters_t *p, int i, char *buffer)
{
    char *prefix = "DELE";
    char *file_fp;

    if (strncmp(buffer, prefix, strlen(prefix)) != 0) {
        return;
    }
    file_fp = full_path(p, i, buffer + strlen(prefix) + 1);
    if (file_fp == NULL) {
        my_write(p->client_sockets[i], "550 Failed to delete file\r\n");
    } else {
        command_delete_check(p, i, file_fp);
        my_free(file_fp);
    }
    p->command_processed = 1;
}

void command_delete_check(parameters_t *p, int i, char *file_fp)
{
    if (invalid_path(file_fp, p) == 1
        || is_file_or_directory(file_fp) != 'f'
        || remove(file_fp) == -1) {
        my_write(p->client_sockets[i], "550 Failed to delete file\r\n");
    } else {
        my_write(p->client_sockets[i], "250 File successfully deleted\r\n");
    }
}

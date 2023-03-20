/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_list.c file.
*/

#include "core.h"

void command_list(parameters_t *p, int i, char *buffer)
{
    char *dir_fp;

    if (strncmp(buffer, "LIST", strlen("LIST")) != 0)
        return;
    if (strcmp(buffer, "LIST") != 0) {
        dir_fp = full_path(p, i, buffer + strlen("LIST") + 1);
        if (dir_fp == NULL || invalid_path(dir_fp, p) == 1
            || is_file_or_directory(dir_fp) != 'd') {
            my_write(p->client_sockets[i], "550 Failed to open directory\r\n");
            p->command_processed = 1;
            my_free(dir_fp);
            return;
        }
        command_list_print(p, i, opendir(dir_fp), dir_fp);
    } else {
        dir_fp = strdup(p->current_path[i]);
        if (dir_fp == NULL)
            return;
        command_list_print(p, i, opendir(p->current_path[i]), dir_fp);
    }
}

void command_list_print(parameters_t *p, int i, DIR *open, char *dir_fp)
{
    struct dirent *read;

    if (open == NULL) {
        my_free(dir_fp);
        my_write(p->client_sockets[i], "550 Failed to open directory\r\n");
        p->command_processed = 1;
        return;
    }
    my_write(p->client_sockets[i], "150 Here comes the directory listing\r\n");
    while ((read = readdir(open)) != NULL) {
        if (read->d_type == DT_REG) {
            my_write(p->client_sockets[i], read->d_name);
            my_write(p->client_sockets[i], "\r\n");
        }
    }
    my_write(p->client_sockets[i], "226 Directory send OK\r\n");
    closedir(open);
    my_free(read);
    my_free(dir_fp);
    p->command_processed = 1;
}

/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_help.c file.
*/

#include "core.h"

void command_help(parameters_t *p, int i, char *buffer)
{
    char *prefix = "HELP";
    char *line;

    if (strncmp(buffer, prefix, strlen(prefix)) != 0)
        return;
    if (strcmp(buffer, prefix) != 0) {
        line = search_line("assets/help", buffer + strlen(prefix) + 1);
        if (line == NULL) {
            my_write(p->client_sockets[i], "502 Command not found\r\n");
        } else {
            my_write(p->client_sockets[i], "214 ");
            my_write(p->client_sockets[i], line);
            (line[strlen(line) - 1] != '\n') ?
                (my_write(p->client_sockets[i], "\r\n")) : (0);
            my_free(line);
        }
    } else {
        command_help_classic(p, i);
    }
    p->command_processed = 1;
}

void command_help_classic(parameters_t *p, int i)
{
    FILE *open;
    char *line = NULL;
    size_t length = 0;

    open = fopen("assets/help", "r");
    if (open == NULL) {
        return;
    }
    while (getline(&line, &length, open) != -1) {
        my_write(p->client_sockets[i], line);
    }
    my_write(p->client_sockets[i], "\r\n");
    my_write(p->client_sockets[i], "214 Here is the list of commands\r\n");
    fclose(open);
    my_free(line);
}

/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** error_handling.c file.
*/

#include "core.h"

void error_handling_throw_if_errors(int ac, char **av, parameters_t *p)
{
    if (ac == 3) {
        error_handling_check_port(av[1], p);
        error_handling_check_path(av[2], p);
    } else {
        error_handling_unknown_command(p);
    }
}

void error_handling_check_port(char *port, parameters_t *p)
{
    char *temp = NULL;
    long int int_port;

    int_port = strtol(port, &temp, 10);
    if (int_port < 1024 || int_port > 65535 ) {
        my_exit(84, "Port isn't between 1024 and 65535\n", p);
    }
    p->port = (int)int_port;
}

void error_handling_check_path(char *path, parameters_t *p)
{
    p->path = real_path(path);
    if (p->path == NULL) {
        my_exit(84, "Path doesn't exist\n", p);
    }
    if (is_file_or_directory(p->path) != 'd') {
        my_exit(84, "Path isn't a directory\n", p);
    }
}

void error_handling_unknown_command(parameters_t *p)
{
    my_exit(84, "Unknown command, please use -help to get the list of"
        " commands\n", p);
}

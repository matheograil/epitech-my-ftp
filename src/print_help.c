/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** print_help.c file.
*/

#include "core.h"

void print_help(int ac, char **av, parameters_t *p)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        my_exit(0, "USAGE: ./myftp port path\n\tport is the port number on "
            "which the server socket listens\n\tpath is the path to the home "
            "directory for the Anonymous user\n", p);
    }
}

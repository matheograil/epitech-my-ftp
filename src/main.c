/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** main.c file.
*/

#include "core.h"

int main(int ac, char **av)
{
    parameters_t *p = malloc(sizeof(parameters_t));

    print_help(ac, av, p);
    error_handling_throw_if_errors(ac, av, p);
    socket_init(p);
    my_exit(0, NULL, p);
}

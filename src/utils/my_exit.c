/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** my_exit.c file.
*/

#include "core.h"

void my_exit(int code, char *message, parameters_t *p)
{
    if (message != NULL) {
        printf("%s", message);
    }
    parameters_destroy(p);
    exit(code);
}

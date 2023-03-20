/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** invalid_path.c file.
*/

#include "core.h"

int invalid_path(char *full_path, parameters_t *p)
{
    if (strstr(full_path, p->path) != NULL) {
        return (0);
    }
    return (1);
}

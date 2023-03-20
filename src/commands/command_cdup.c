/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** command_cdup.c file.
*/

#include "core.h"

void command_cdup(parameters_t *p, int i, char *buffer)
{
    char *cdup_cmd = "CDUP";

    if (strcmp(buffer, cdup_cmd) != 0) {
        return;
    }
    command_cwd(p, i, "CWD ..", "200");
}

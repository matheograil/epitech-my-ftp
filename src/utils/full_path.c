/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** full_path.c file.
*/

#include "core.h"

char *full_path(parameters_t *p, int i, char *relative_path)
{
    char *full_path;
    char *temp;
    char *temp2;

    if (relative_path[0] == '/') {
        full_path = real_path(relative_path);
    } else {
        temp = concat_strings(p->current_path[i], "/");
        if (temp == NULL)
            return (NULL);
        temp2 = concat_strings(temp, relative_path);
        my_free(temp);
        if (temp2 == NULL)
            return (NULL);
        full_path = real_path(temp2);
        my_free(temp2);
    }
    if (full_path == NULL)
        return (NULL);
    return (full_path);
}

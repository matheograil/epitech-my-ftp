/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** real_path.c file.
*/

#include "core.h"

char *real_path(char *relative_path)
{
    char *full_path = realpath(relative_path, NULL);

    if (full_path == NULL) {
        return (NULL);
    }
    full_path = malloc((strlen(full_path) + 1) * sizeof(char));
    if (full_path == NULL || realpath(relative_path, full_path) == NULL) {
        my_free(full_path);
        return (NULL);
    }
    return (full_path);
}

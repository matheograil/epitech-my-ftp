/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** is_file_or_directory.c file.
*/

#include "core.h"

char is_file_or_directory(char *full_path)
{
    struct stat fp_info;

    if (stat(full_path, &fp_info) == -1) {
        return ('u');
    }
    if (S_ISDIR(fp_info.st_mode)) {
        return ('d');
    } else if (S_ISREG(fp_info.st_mode)) {
        return ('f');
    }
    return ('u');
}

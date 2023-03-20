/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** search_line.c file.
*/

#include "core.h"

char *search_line(char *file_fp, char *query)
{
    FILE *open;
    char *line = NULL;
    size_t length = 0;

    open = fopen(file_fp, "r");
    if (open == NULL) {
        return (NULL);
    }
    while (getline(&line, &length, open) != -1) {
        if (strstr(line, query) != NULL) {
            fclose(open);
            return (line);
        }
    }
    fclose(open);
    my_free(line);
    return (NULL);
}

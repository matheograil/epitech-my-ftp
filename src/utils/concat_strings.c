/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** concat_strings.c file.
*/

#include "core.h"

char *concat_strings(char *str1, char *str2)
{
    char *result = malloc(sizeof(char) * (strlen(str1)
        + strlen(str2) + 1));
    int i = 0;
    int j = 0;

    if (result == NULL) {
        return (NULL);
    }
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return (result);
}

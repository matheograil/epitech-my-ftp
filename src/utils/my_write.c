/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** my_write.c file.
*/

#include "core.h"

void my_write(int socket, char *message)
{
    write(socket, message, strlen(message));
}

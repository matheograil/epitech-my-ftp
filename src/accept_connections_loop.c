/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** accept_connections_loop.c file.
*/

#include "core.h"

void accept_connections_loop(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "220 Connected\r\n");
}

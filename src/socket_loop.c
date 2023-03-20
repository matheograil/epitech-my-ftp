/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** socket_loop.c file.
*/

#include "core.h"

_Noreturn void socket_loop(parameters_t *p)
{
    parameters_init(p);
    printf("Server started on port %d\n", p->port);
    while (1) {
        FD_ZERO(&p->sockets);
        FD_SET(p->current_socket, &p->sockets);
        p->temporary_socket = p->current_socket;
        socket_loop_add_clients(p);
        socket_loop_select(p);
        socket_loop_accept_connections(p);
        socket_loop_handle_connections(p);
    }
}

void socket_loop_add_clients(parameters_t *p)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (p->client_sockets[i] == 0) {
            continue;
        }
        FD_SET(p->client_sockets[i], &p->sockets);
        if (p->client_sockets[i] > p->temporary_socket) {
            p->temporary_socket = p->client_sockets[i];
        }
    }
}

void socket_loop_select(parameters_t *p)
{
    if (select(p->temporary_socket + 1, &p->sockets, NULL, NULL, NULL) == -1) {
        my_exit(84, "Socket (select) failed\n", p);
    }
}

void socket_loop_accept_connections(parameters_t *p)
{
    struct sockaddr_in client_socket_address;
    socklen_t client_socket_address_size;
    int new_client_socket;

    if (FD_ISSET(p->current_socket, &p->sockets) <= 0)
        return;
    client_socket_address_size = sizeof(client_socket_address);
    new_client_socket = accept(p->current_socket,
        (struct sockaddr *)&client_socket_address,
        &client_socket_address_size);
    if (new_client_socket == -1)
        my_exit(84, "Socket (accept) failed\n", p);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (p->client_sockets[i] == 0) {
            p->client_sockets[i] = new_client_socket;
            accept_connections_loop(p, i);
            break;
        }
    }
}

void socket_loop_handle_connections(parameters_t *p)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (FD_ISSET(p->client_sockets[i], &p->sockets) > 0) {
            connections_loop(p, i);
        }
    }
}

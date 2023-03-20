/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** parameters.c file.
*/

#include "core.h"

void parameters_init(parameters_t *p)
{
    p->client_sockets = malloc(sizeof(int) * MAX_CLIENTS);
    p->username_provided = malloc(sizeof(int) * MAX_CLIENTS);
    p->client_logged_in = malloc(sizeof(int) * MAX_CLIENTS);
    p->current_path = malloc(sizeof(char *) * MAX_CLIENTS);
    if (p->client_sockets == NULL || p->username_provided == NULL
        || p->client_logged_in == NULL || p->current_path == NULL) {
        my_free(p->client_sockets);
        my_free(p->username_provided);
        my_free(p->client_logged_in);
        my_free(p->current_path);
        my_exit(84, "Malloc (parameters) failed\n", p);
    }
    for (int i = 0; i < MAX_CLIENTS; i++) {
        close_socket(p, i, 0);
    }
}

void parameters_destroy(parameters_t *p)
{
    if (p->current_path != NULL) {
        for (int i = 0; i < MAX_CLIENTS; i++) {
            my_free(p->current_path[i]);
        }
        my_free(p->current_path);
    }
    my_free(p->client_sockets);
    my_free(p->username_provided);
    my_free(p->client_logged_in);
    my_free(p->path);
    my_free(p);
}

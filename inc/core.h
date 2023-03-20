/*
** EPITECH PROJECT, 2023
** MyFTP
** File description:
** core.h file.
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_CLIENTS 15
#define BUFFER_SIZE 1024

typedef struct parameters_s {
    int port;
    char *path;
    int current_socket;
    int temporary_socket;
    fd_set sockets;
    int *client_sockets;
    int *username_provided;
    int *client_logged_in;
    int command_processed;
    char **current_path;
} parameters_t;

void command_cdup(parameters_t *, int, char *);
void command_noop(parameters_t *, int, char *);
void command_cwd(parameters_t *, int, char *, char *);
void command_cwd_check(parameters_t *, int, char *, char *);
void command_username(parameters_t *, int, char *);
void command_password(parameters_t *, int, char *);
void command_quit(parameters_t *, int, char *);
void command_pwd(parameters_t *, int, char *);
void command_delete(parameters_t *, int, char *);
void command_delete_check(parameters_t *, int, char *);
void command_list(parameters_t *, int, char *);
void command_list_print(parameters_t *, int, DIR *, char *);
void command_help(parameters_t *, int, char *);
void command_help_classic(parameters_t *, int);

void close_socket(parameters_t *, int, int);
char *concat_strings(char *, char *);
char *full_path(parameters_t *, int, char *);
int invalid_path(char *, parameters_t *);
char is_file_or_directory(char *);
void my_free(void *);
void my_write(int, char *);
char *real_path(char *);
char *search_line(char *, char *);

void accept_connections_loop(parameters_t *, int);

void connections_loop(parameters_t *, int);
void connections_loop_read(parameters_t *, int, char *);

void error_handling_throw_if_errors(int, char **, parameters_t *);
void error_handling_check_port(char *, parameters_t *);
void error_handling_check_path(char *, parameters_t *);
void error_handling_unknown_command(parameters_t *);

void parameters_init(parameters_t *);
void parameters_destroy(parameters_t *);

int main(int, char **);

void my_exit(int, char *, parameters_t *);

void print_help(int, char **, parameters_t *);

void socket_init(parameters_t *);
void socket_create(parameters_t *);

_Noreturn void socket_loop(parameters_t *);
void socket_loop_add_clients(parameters_t *);
void socket_loop_select(parameters_t *);
void socket_loop_accept_connections(parameters_t *);
void socket_loop_handle_connections(parameters_t *);

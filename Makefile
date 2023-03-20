##
## EPITECH PROJECT, 2023
## MyFTP
## File description:
## MAKEFILE file.
##

SRC = src/main.c \
	src/print_help.c \
	src/error_handling.c \
	src/utils/my_exit.c \
	src/socket.c \
	src/socket_loop.c \
	src/connections_loop.c \
	src/accept_connections_loop.c \
	src/parameters.c \
	src/commands/command_delete.c \
	src/commands/command_password.c \
	src/commands/command_pwd.c \
	src/commands/command_quit.c \
	src/commands/command_username.c \
	src/commands/command_list.c \
	src/utils/invalid_path.c \
	src/utils/is_file_or_directory.c \
	src/utils/my_write.c \
	src/utils/concat_strings.c \
	src/commands/command_cwd.c \
	src/utils/real_path.c \
	src/utils/full_path.c \
	src/commands/command_noop.c \
	src/commands/command_cdup.c \
	src/commands/command_help.c \
	src/utils/search_line.c \
	src/utils/close_socket.c \
	src/utils/my_free.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror -I ./inc

NAME = myftp

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

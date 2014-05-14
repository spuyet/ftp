# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/13 08:56:26 by spuyet            #+#    #+#              #
#    Updated: 2014/05/13 11:37:41 by spuyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CFLAGS = -Wall -Wextra -Werror -I include -I libft/includes

S_FILES = s_child.c s_cmd.c s_create.c s_ls.c s_main.c s_pwd.c s_run.c \
s_usage.c utils.c \

C_FILES = c_args.c c_cmd.c c_create.c c_list.c c_ls.c c_main.c c_pwd.c \
c_run.c c_usage.c utils.c \

LIBFT = libft

S_SRC = $(addprefix src/, $(S_FILES))

C_SRC = $(addprefix src/, $(C_FILES))

S_OBJ = $(S_FILES:.c=.o)

C_OBJ = $(C_FILES:.c=.o)

S_NAME = serveur

C_NAME = client

all: lib s c

s: $(S_NAME)

c: $(C_NAME)

lib:
	@(echo "Compiling library...\c")
	@(make -C $(LIBFT))
	@(echo "\x1b[32;01mOK\x1b[0m")

$(S_NAME): $(S_OBJ)
	@(echo "Compiling server files...\c")
	@($(CC) -L$(LIBFT) -lft $^ -o $@)
	@(echo "\x1b[32;01mOK\x1b[0m")

$(C_NAME): $(C_OBJ)
	@(echo "Compiling client files...\c")
	@($(CC) -L$(LIBFT) -lft $^ -o $@)
	@(echo "\x1b[32;01mOK\x1b[0m")

%.o: src/%.c
	@($(CC) $(CFLAGS) -c $<)

clean:
	@(echo "Destroying server: objects files...\c")
	@(rm -rf $(S_OBJ))
	@(echo "\x1b[32;01mOK\x1b[0m")
	@(echo "Destroying client: objects files...\c")
	@(rm -rf $(C_OBJ))
	@(echo "\x1b[32;01mOK\x1b[0m")
	@(echo "Destroying library: objects files...\c")
	@(make -C $(LIBFT) $@)
	@(echo "\x1b[32;01mOK\x1b[0m")

fclean: clean
	@(echo "Destroying server binary...\c")
	@(rm -rf $(S_NAME))
	@(echo "\x1b[32;01mOK\x1b[0m")
	@(echo "Destroying client binary...\c")
	@(rm -rf $(C_NAME))
	@(echo "\x1b[32;01mOK\x1b[0m")
	@(echo "Destroying library binary...\c")
	@(make -C $(LIBFT) $@)
	@(echo "\x1b[32;01mOK\x1b[0m")

re: fclean all


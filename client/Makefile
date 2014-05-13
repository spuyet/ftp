# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/13 08:56:26 by spuyet            #+#    #+#              #
#    Updated: 2014/05/13 13:24:08 by spuyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CFLAGS = -Wall -Wextra -Werror -I ../include -I ../libft/includes

FILES = main.c msg.c nan.c init.c \

LIBFT = ../libft

SRC = $(addprefix src/, $(FILES))

OBJ = $(FILES:.c=.o)

NAME = client 

all: $(NAME)

$(NAME): $(OBJ)
	@(echo "Compiling library...\c")
	@(make -C $(LIBFT))
	@(echo "\x1b[32;01mOK\x1b[0m")
	@(echo "Compiling project files...\c")
	@($(CC) -L$(LIBFT) -lft $^ -o $@)
	@(echo "\x1b[32;01mOK\x1b[0m")

%.o: src/%.c
	@($(CC) $(CFLAGS) -c $<)

clean:
	@(echo "Destroying project: objects files...\c")
	@(rm -rf $(OBJ))
	@(echo "\x1b[32;01mOK\x1b[0m")
	@(echo "Destroying library: objects files...\c")
	@(make -C $(LIBFT) $@)
	@(echo "\x1b[32;01mOK\x1b[0m")

fclean: clean
	@(echo "Destroying project: binary file...\c")
	@(rm -rf $(NAME))
	@(echo "\x1b[32;01mOK\x1b[0m")
	@(echo "Destroying library: binary file...\c")
	@(make -C $(LIBFT) $@)
	@(echo "\x1b[32;01mOK\x1b[0m")

re: fclean all


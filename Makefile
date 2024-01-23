# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:30:44 by ottouti           #+#    #+#              #
#    Updated: 2024/01/23 14:15:35 by ottouti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include/ -fsanitize=address
DEBUGFLAGS = -g
LDFLAGS = -L $(LIBFT_DIR) -lft -fsanitize=address
RM = rm -f
LIBFT_DIR = ./src/libft/
SRCS_DIR = ./src/

SERVER_FILES = init_server 
CLIENT_FILES = init_client 

SERVER_SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SERVER_FILES)))
CLIENT_SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(CLIENT_FILES)))

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: libft server client

libft:
	$(MAKE) --silent -C $(LIBFT_DIR)

server: $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o server $(LDFLAGS)

client: $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o client $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: re

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) server client
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

valgrind_server: server
	valgrind --leak-check=full ./server

valgrind_client: client
	valgrind --leak-check=full ./client

.PHONY: all clean fclean re debug libft server client valgrind_server valgrind_client

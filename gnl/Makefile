# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 16:26:01 by shimakaori        #+#    #+#              #
#    Updated: 2023/06/06 16:25:43 by shimakaori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libgnl.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I include
GNL_DIR		= gnl
VPATH 		= srcs
SRCS		= get_next_line.c      \
			  get_next_line_utils.c
OBJS		= $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f srcs/*.out

re: fclean all

.PHONY: all .c.o clean fclean re

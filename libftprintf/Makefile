# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 12:55:48 by shimakaori        #+#    #+#              #
#    Updated: 2022/10/07 10:38:37 by shimakaori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT_DIR	=./libft
LIBFT		= libft.a
INCLUDE		= ./include
SRCS		= ft_printf.c\
			  ft_printchar.c\
			  ft_printstr.c\
			  ft_printnbr.c\
			  ft_printnbr_unsigned.c\
			  ft_printhex.c\
			  ft_printaddr.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS) *.out
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all .c.o clean fclean re

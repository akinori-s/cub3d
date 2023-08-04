# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 13:14:55 by shimakaori        #+#    #+#              #
#    Updated: 2023/08/05 00:06:53 by asasada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LIBFTPRINTF_DIR	= libftprintf
GNL_DIR			= gnl
MINILIBX_DIR	= minilibx-linux
X11_DIR 		= /usr/X11
INCLUDE			= -I include -I $(LIBFTPRINTF_DIR)/include -I $(GNL_DIR)/include -I $(MINILIBX_DIR) -I$(X11_DIR)/include
LIBS_DIR 		= -L$(LIBFTPRINTF_DIR) -L$(GNL_DIR) -L$(MINILIBX_DIR) -L$(X11_DIR)/lib -L$(X11_DIR)/include
LIBS 			= -lftprintf -lgnl -lmlx -lX11 -lXext -lm
VPATH 			= srcs
SRCS			= main.c         \
				  init_game.c    \
				  set_game.c     \
				  is_walled.c    \
				  texture.c      \
				  get_wall.c     \
				  draw_wall.c    \
				  move_player.c  \
				  utils.c        \
				  bool.c         \
				  read_map.c	 \
				  read_map_info.c\
				  draw_minimap.c \
				  test_print.c   
OBJ_DIR			= objs
OBJS			= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

BINCLUDE			= -I bonus_include -I $(LIBFTPRINTF_DIR)/include -I $(GNL_DIR)/include -I $(MINILIBX_DIR) -I$(X11_DIR)/include
BPATH			= bonus
BSRCS			= main_bonus.c         \
				  init_game_bonus.c    \
				  set_game_bonus.c     \
				  is_walled_bonus.c    \
				  texture_bonus.c      \
				  get_wall_bonus.c     \
				  draw_wall_bonus.c    \
				  move_player_bonus.c  \
				  utils_bonus.c        \
				  bool_bonus.c         \
				  read_map_bonus.c	 \
				  read_map_info_bonus.c\
				  draw_minimap_bonus.c
BOBJ_DIR		= bonus_objs
BOBJS			= $(addprefix $(BOBJ_DIR)/, $(BSRCS:%.c=%.o))

UNAME = $(shell uname)
ifeq ($(UNAME), Darwin)
	LIBS_DIR 	+= -L/usr/X11R6/lib
	LIBS 		+= -lmlx_Darwin -framework OpenGL -framework AppKit
else
	LIBS 		+= -lmlx_Linux
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $^ $(LIBS_DIR) $(LIBS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) -c $< -o $@

$(BOBJ_DIR)/%.o: $(BPATH)/%.c
	@mkdir -p $$(dirname $@)
	$(CC) $(BINCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BOBJ_DIR)
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR)

re: fclean all

bonus: $(BOBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $^ $(LIBS_DIR) $(LIBS) -o $(NAME)

sanitize: CFLAGS += -g -fsanitize=address
sanitize: re

norm:
	norminette $(VPATH) $(BPATH) include
normall:
	norminette $(VPATH) $(BPATH) include $(LIBFTPRINTF_DIR) $(GNL_DIR)

.PHONY: all clean fclean re bonus .c.o 
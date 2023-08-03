/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:30:23 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/03 23:18:04 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "X11/X.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//key_event
# define ESC_KEY		0xff1b
# define LEFT_KEY		0xff51
# define RIGHT_KEY		0xff53
# define W_KEY 			0x0077
# define A_KEY 			0x0061
# define S_KEY 			0x0073
# define D_KEY 			0x0064

//size
# define SCREENWIDTH	640
# define SCREENHEIGHT 	480

//player
# define PLAYER_MOVE_PX	0.023

#define GRID_SIZE 8
#define PLAYER_SIZE 4
#define RAY_SIZE 16
#define MINIMAP_WIDTH 7
#define MINIMAP_HEIGHT 7
#define MINIMAP_WALL_COLOR 0x00FF00
#define MINIMAP_EMPTY_COLOR 0x000000
#define MINIMAP_PLAYER_COLOR 0xFF0000
#define MINIMAP_RAY_COLOR 0x0000FF

typedef struct s_dvector
{
	double		x;
	double		y;
}				t_dvector;

typedef struct s_ivector
{
	int			x;
	int			y;
}				t_ivector;

typedef struct s_img
{
	char		*path;
	void		*image;
	char		*buffer;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	char		**map2d;
	size_t		height;
	size_t		width;
	t_img		north_tex;
	t_img		south_tex;
	t_img		west_tex;
	t_img		east_tex;
	char		*f_color;
	char		*c_color;
}				t_map;

typedef struct s_player
{
	t_dvector	pos;
	t_dvector	dir;
	t_dvector	plane;
	double		plane_len;
	int			is_move_ns;
	int			is_move_ew;
	int			is_turning;
}	t_player;

typedef struct s_ray
{
	double		camera_x;
	t_ivector	map;
	t_dvector	ray_dir;
	t_dvector	side_dist;
	t_dvector	delta_dist;
	t_ivector	step;
	int			side_ns;
	double		perp_wall_dist;
	double		zbuf[SCREENWIDTH];
}	t_ray;

typedef struct s_wall
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_ivector	tex;
	double		wall_x;
	double		step;
	double		tex_pos;
	double		height_base;
	uint32_t	color;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	t_img		*tex_img;
}				t_wall;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		mini_img;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
}				t_game;

// set_game.c
void		set_game(t_game *game, char *file);

// init_game.c
t_game		init_game(t_game game);

// texture.c
void		load_texture(t_game *game, t_map *map);
void		read_background_color(t_map *map, t_wall *wall);
uint32_t	convert_color(char *color);
uint32_t	get_color(t_img img, int x, int y);
void		set_color(t_img *img, int x, int y, int color);

// draw_wall.c
void		draw_wall(t_game *game);

// get_wall.c
void		get_rayinfo(t_player *player, t_ray *ray, size_t x);
void		get_step_sidedist(t_player *player, t_ray *ray);
void		get_wallinfo(t_wall *wall, t_ray *ray, t_player *player);

// move_player.c
void		move_player(t_game *game);

// utils.c
void		set_screen(t_game *game, t_img *img, t_img *mini_img);
void		free_map(t_map *map);
void		free_2darray(char **array);
size_t		ft_2darray_len(char **array);
void		error_exit(char *str);

// bool.c
bool		check_texfile(char *file);
bool		is_news(char c);
bool		is_chara(char c);
bool		is_digit_str(char *str);
bool		is_char_iter(char *str, bool (*f)(char));

// is_walled.c
bool		is_walled(t_map *map, int x, int y);

// read_map.c
int			read_map(t_game *game, char *next_line, int fd);

// read_map_info.c
char		*read_map_info(int fd, t_game *game);

void		draw_minimap(t_map *map, t_player *player, t_img *img);

//test_print.c
void		print_map(t_map *map);
void		print_player(t_player *player);
void		print_ray(t_ray *ray);
void		print_wall(t_wall *wall);
void		print_copy(t_map *map, char **copy);

#endif
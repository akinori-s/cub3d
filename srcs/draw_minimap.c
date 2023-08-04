/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:37:57 by asasada           #+#    #+#             */
/*   Updated: 2023/08/04 23:02:10 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void	draw_square(t_img *img, int start_x, int start_y, int size, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			set_color(img, start_x + x, start_y + y, color);
			y++;
		}
		x++;
	}
}

void	fill_minimap(t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < GRID_SIZE * MINIMAP_WIDTH)
	{
		y = 0;
		while (y < GRID_SIZE * MINIMAP_HEIGHT)
		{
			set_color(img, x, y, MINIMAP_WALL_COLOR);
			y++;
		}
		x++;
	}
}

void	draw_player(t_img *img)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = (MINIMAP_WIDTH * GRID_SIZE) / 2 - (PLAYER_SIZE / 2);
	start_y = (MINIMAP_HEIGHT * GRID_SIZE) / 2 - (PLAYER_SIZE / 2);
	x = 0;
	while (x < PLAYER_SIZE)
	{
		y = 0;
		while (y < PLAYER_SIZE)
		{
			set_color(img, start_x + x, start_y + y, MINIMAP_PLAYER_COLOR);
			y++;
		}
		x++;
	}
}

void	draw_ray(t_img *img, t_player *player)
{
	int	i;
	int	start_x;
	int	start_y;
	int	ray_x;
	int	ray_y;

	i = 0;
	ray_x = 0;
	ray_y = 0;
	start_x = (MINIMAP_WIDTH * GRID_SIZE) / 2;
	start_y = (MINIMAP_HEIGHT * GRID_SIZE) / 2;
	while (i < RAY_SIZE)
	{
		ray_x = start_x + (int)(player->dir.x * i);
		ray_y = start_y + (int)(player->dir.y * i);
		set_color(img, ray_x, ray_y, MINIMAP_RAY_COLOR);
		i++;
	}
}

void	draw_minimap(t_map *map, t_player *player, t_img *img)
{
	static int counter = 0;
	fill_minimap(img);
	int	x;
	int	y;

	// draw empty space
	int	x_end;
	int	y_end;
	int x_start;
	int y_start;

	x = fmax(0, (int)player->pos.x - (MINIMAP_WIDTH / 2) - 1);
	y = fmax(0, (int)player->pos.y - (MINIMAP_HEIGHT / 2) - 1);
	x_end = fmin(map->width - 1, (int)player->pos.x + (MINIMAP_WIDTH / 2) + 2);
	y_end = fmin(map->height - 1, (int)player->pos.y + (MINIMAP_HEIGHT / 2) + 2);
	// x_start = x - (int)player->pos.x;
	// y_start = y - (int)player->pos.y;
	x_start = x;
	y_start = y;
	// x_end = x_end - (int)player->pos.x;
	// y_end = y_end - (int)player->pos.y;

	int	i;
	int	j;

	int x_tmp;
	int y_tmp;

	if (counter == 0)
		printf("map width: %d, map height: %d\n", map->width, map->height);
	// if (counter % 240 == 0)
	// {
	// 	printf("x: %d, y: %d\n", (int)player->pos.x, (int)player->pos.y);
	// 	printf("x_start: %d, y_start: %d\n", x_start, y_start);
	// 	printf("x_end: %d, y_end: %d\n", x_end, y_end);
	// }
		// printf("x: %d, y: %d\n", (int)player->pos.x, (int)player->pos.y);
		// printf("x_start: %d, y_start: %d\n", x_start, y_start);
		// printf("x_end: %d, y_end: %d\n", x_end, y_end);
	counter++;
	// printf("aaaaa\n");
	i = 0;
	while (x_start < x_end)
	{
		y_start = y;
		while (y_start < y_end)
		{
			// printf("bbbbbbbbbbbb\n");
			// if (counter % 30 == 0)
			// 	printf("x: %d, y: %d\n", (int)(player->pos.x) + x_start, (int)(player->pos.y) + y_start);
			// if (map->map2d[(int)(player->pos.y) + y_start][(int)(player->pos.x) + x_start] == '0')
				// printf("x: %d, y: %d\n", x_start, y_start);
			if (map->map2d[y_start][x_start] == '0' || is_news(map->map2d[y_start][x_start]))
			{
				// printf("cccccccccccccc\n");
				int	x_offset;
				int	y_offset;

				i = 0;
				x_offset = (x_start - (int)player->pos.x) * GRID_SIZE + MINIMAP_WIDTH * GRID_SIZE / 2 - (player->pos.x - (int)player->pos.x) * GRID_SIZE;
				y_offset = (y_start - (int)player->pos.y) * GRID_SIZE + MINIMAP_HEIGHT * GRID_SIZE / 2 - (player->pos.y - (int)player->pos.y) * GRID_SIZE;
				while (i < GRID_SIZE)
				{
					j = 0;
					while (j < GRID_SIZE)
					{
						// printf("x: %d, y: %d\n", (x_start * GRID_SIZE + i - MINIMAP_WIDTH * GRID_SIZE / 2), (y_start * GRID_SIZE + j - MINIMAP_HEIGHT * GRID_SIZE / 2));
						// x_tmp = x_start - (int)player->pos.x * GRID_SIZE + i + MINIMAP_WIDTH * GRID_SIZE / 2 + (player->pos.x - (int)player->pos.x) * GRID_SIZE;
						// y_tmp =  y_start - (int)player->pos.y * GRID_SIZE + j + MINIMAP_HEIGHT * GRID_SIZE / 2 + (player->pos.y - (int)player->pos.y) * GRID_SIZE;
						// if (x_tmp >= 0 && x_tmp < MINIMAP_WIDTH * GRID_SIZE && \
						// 	y_tmp >= 0 && y_tmp < MINIMAP_HEIGHT * GRID_SIZE)
						x_tmp = x_offset + i;
						y_tmp = y_offset + j;
						if (x_tmp >= 0 && x_tmp < MINIMAP_WIDTH * GRID_SIZE && \
							y_tmp >= 0 && y_tmp < MINIMAP_HEIGHT * GRID_SIZE)
						{
							// printf("x: %d, y: %d\n", (x * GRID_SIZE + i + MINIMAP_WIDTH * GRID_SIZE / 2), (y * GRID_SIZE + j + MINIMAP_HEIGHT * GRID_SIZE / 2));
							set_color(img, x_tmp, y_tmp, MINIMAP_EMPTY_COLOR);
						}
						j++;

					}
					i++;
				}
			}
			y_start++;
		}
		x_start++;
	}

	// draw player
	draw_player(img);
	// draw rays
	draw_ray(img, player);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:37:57 by asasada           #+#    #+#             */
/*   Updated: 2023/08/04 23:18:22 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_minimap(t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < GRID_SIZE * MINIMAP_W)
	{
		y = 0;
		while (y < GRID_SIZE * MINIMAP_H)
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

	start_x = (MINIMAP_W * GRID_SIZE) / 2 - (PLAYER_SIZE / 2);
	start_y = (MINIMAP_H * GRID_SIZE) / 2 - (PLAYER_SIZE / 2);
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
	start_x = (MINIMAP_W * GRID_SIZE) / 2;
	start_y = (MINIMAP_H * GRID_SIZE) / 2;
	while (i < RAY_SIZE)
	{
		ray_x = start_x + (int)(player->dir.x * i);
		ray_y = start_y + (int)(player->dir.y * i);
		set_color(img, ray_x, ray_y, MINIMAP_RAY_COLOR);
		i++;
	}
}

void	draw_minimap_grid(t_img *img, t_player *player, int x_star, int y_star)
{
	int	i;
	int	j;
	int	x_off;
	int	y_off;

	i = 0;
	x_off = (x_star - (int)player->pos.x) * GRID_SIZE + MINIMAP_W * \
		GRID_SIZE / 2 - (player->pos.x - (int)player->pos.x) * GRID_SIZE;
	y_off = (y_star - (int)player->pos.y) * GRID_SIZE + MINIMAP_H * \
		GRID_SIZE / 2 - (player->pos.y - (int)player->pos.y) * GRID_SIZE;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			if (x_off + i >= 0 && x_off + i < MINIMAP_W * GRID_SIZE && \
				y_off + j >= 0 && y_off + j < MINIMAP_H * GRID_SIZE)
				set_color(img, x_off + i, y_off + j, MINIMAP_EMPTY_COLOR);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_map *map, t_player *player, t_img *img)
{
	int	y;
	int	x_end;
	int	y_end;
	int	x_start;
	int	y_start;

	fill_minimap(img);
	y = fmax(0, (int)player->pos.y - (MINIMAP_H / 2) - 1);
	x_end = fmin(map->width - 1, (int)player->pos.x + (MINIMAP_W / 2) + 2);
	y_end = fmin(map->height - 1, (int)player->pos.y + (MINIMAP_H / 2) + 2);
	x_start = fmax(0, (int)player->pos.x - (MINIMAP_W / 2) - 1);
	while (x_start < x_end)
	{
		y_start = y;
		while (y_start < y_end)
		{
			if (map->map2d[y_start][x_start] == '0' || \
				is_news(map->map2d[y_start][x_start]))
				draw_minimap_grid(img, player, x_start, y_start);
			y_start++;
		}
		x_start++;
	}
	draw_player(img);
	draw_ray(img, player);
}

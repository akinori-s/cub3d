/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:37:57 by asasada           #+#    #+#             */
/*   Updated: 2023/08/03 23:17:16 by asasada          ###   ########.fr       */
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

void	draw_minimap(t_map *map, t_player *player, t_img *img)
{
	// image already initialized
	// fill image with wall color
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

	// draw walls


	// draw empty space

	// draw player
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
	// draw rays

	int	i;
	int	ray_x;
	int	ray_y;

	i = 0;
	ray_x = 0;
	ray_y = 0;
	start_x = (MINIMAP_WIDTH * GRID_SIZE) / 2 - (PLAYER_SIZE / 2);
	start_y = (MINIMAP_HEIGHT * GRID_SIZE) / 2 - (PLAYER_SIZE / 2);
	while (i < RAY_SIZE)
	{
		ray_x = start_x + (int)(player->dir.x) * i;
		ray_y = start_y + (int)(player->dir.y) * i;
		set_color(img, ray_x, ray_y, MINIMAP_RAY_COLOR);
		i++;
	}

}

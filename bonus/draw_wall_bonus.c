/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:42:36 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/04 23:57:59 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void		raycasting(t_map *map, t_ray *ray);
void		get_perpdist_teximg(t_map *map, t_ray *ray, t_wall *wall);
void		draw_stripe(t_game *game, t_wall *wall, size_t x);

void	draw_wall(t_game *game)
{
	size_t	x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		get_rayinfo(&game->player, &game->ray, x);
		get_step_sidedist(&game->player, &game->ray);
		raycasting(&game->map, &game->ray);
		get_perpdist_teximg(&game->map, &game->ray, &game->wall);
		game->ray.zbuf[x] = game->ray.perp_wall_dist;
		get_wallinfo(&game->wall, &game->ray, &game->player);
		draw_stripe(game, &game->wall, x);
		x++;
	}
}

//perform DDA
//jump to next map square, either in x-direction, or in y-direction
void	raycasting(t_map *map, t_ray *ray)
{
	while (map->map2d[ray->map.y][ray->map.x] != '1')
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side_ns = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side_ns = 1;
		}
	}
}

//Calculate distance of perpendicular ray
void	get_perpdist_teximg(t_map *map, t_ray *ray, t_wall *wall)
{
	if (ray->side_ns == 0)
	{
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
		if (ray->step.x > 0)
			wall->tex_img = &map->east_tex;
		else
			wall->tex_img = &map->west_tex;
	}
	else
	{
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
		if (ray->step.y > 0)
			wall->tex_img = &map->south_tex;
		else
			wall->tex_img = &map->north_tex;
	}
}

void	draw_stripe(t_game *game, t_wall *wall, size_t x)
{
	size_t	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		if (y <= SCREENHEIGHT / 2)
			set_color(&(game->img), x, y, wall->ceiling_color);
		else
			set_color(&(game->img), x, y, wall->floor_color);
		if (y >= wall->draw_start && y < wall->draw_end)
		{
			wall->tex.y = (int)wall->tex_pos;
			if (wall->tex.y >= wall->tex_img->height)
				wall->tex.y = wall->tex_img->height - 1;
			wall->tex_pos += wall->step;
			wall->color = get_color(*wall->tex_img, wall->tex.x, wall->tex.y);
			if (game->ray.side_ns == 1)
				wall->color = (wall->color >> 1) & 8355711;
			set_color(&(game->img), x, y, wall->color);
		}
		y++;
	}
}

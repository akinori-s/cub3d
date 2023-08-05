/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:53:15 by shimakaori        #+#    #+#             */
/*   Updated: 2023/06/15 15:54:39 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//calculate ray position and direction
//delta_dist is the length of ray from one x or y-side to next x or y-side
void	get_rayinfo(t_player *player, t_ray *ray, size_t x)
{
	ray->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	ray->ray_dir.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->ray_dir.y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	if ((1 / ray->ray_dir.x) < 0)
		ray->delta_dist.x = -1 * (1 / ray->ray_dir.x);
	else
		ray->delta_dist.x = 1 / ray->ray_dir.x;
	if (1 / ray->ray_dir.y < 0)
		ray->delta_dist.y = -1 * (1 / ray->ray_dir.y);
	else
		ray->delta_dist.y = 1 / ray->ray_dir.y;
}

//calculate what direction to step in
//and length of ray from current position to next x or y-side
void	get_step_sidedist(t_player *player, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x) \
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y) \
			* ray->delta_dist.y;
	}
}

//Calculate height of line to draw on screen
//calculate lowest and highest pixel to fill in current stripe
//calculate value of wall_x where exactly the wall was hit
void	get_wallinfo(t_wall *wall, t_ray *ray, t_player *player)
{
	wall->line_height = (int)(wall->height_base / ray->perp_wall_dist);
	wall->draw_start = -wall->line_height / 2 + SCREENHEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + SCREENHEIGHT / 2;
	if (wall->draw_end >= SCREENHEIGHT)
		wall->draw_end = SCREENHEIGHT - 1;
	if (ray->side_ns == 0)
		wall->wall_x = player->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall->wall_x = player->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex.x = (int)(wall->wall_x * wall->tex_img->width);
	if ((ray->side_ns == 0 && ray->ray_dir.x < 0) || \
		(ray->side_ns == 1 && ray->ray_dir.y > 0))
		wall->tex.x = wall->tex_img->width - wall->tex.x - 1;
	wall->step = 1.0 * wall->tex_img->height / (double)wall->line_height;
	wall->tex_pos = (wall->draw_start - SCREENHEIGHT / 2 \
		+ wall->line_height / 2) * wall->step;
	wall->height_base = (double)SCREENWIDTH * (1 / (2 * player->plane_len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:54:50 by shimakaori        #+#    #+#             */
/*   Updated: 2023/07/26 22:08:05 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_map *map)
{
	size_t	i;

	i = 0;
	printf("-----map-----\n");
	printf("north: %s\n", map->north_tex.path);
	printf("south: %s\n", map->south_tex.path);
	printf("west: %s\n", map->west_tex.path);
	printf("east: %s\n", map->east_tex.path);
	printf("f_color: %s\n", map->f_color);
	printf("c_color: %s\n", map->c_color);
	i = 0;
	while (map->map2d[i] != NULL)
	{
		printf("[%zu]%s\n", i, map->map2d[i]);
		i++;
	}
	printf("height: %zu\n", map->height);
	printf("width: %zu\n", map->width);
}

void	print_player(t_player *player)
{
	printf("-----player-----\n");
	printf("pos.x: %f\n", player->pos.x);
	printf("pos.y: %f\n", player->pos.y);
	printf("dir.x: %f\n", player->dir.x);
	printf("dir.y: %f\n", player->dir.y);
	printf("plane.x: %f\n", player->plane.x);
	printf("plane.y: %f\n", player->plane.y);
	printf("plane_len: %f\n", player->plane_len);
	printf("is_move_ns: %d\n", player->is_move_ns);
	printf("is_move_ew: %d\n", player->is_move_ew);
	printf("is_turning: %d\n", player->is_turning);
}

void	print_ray(t_ray *ray)
{
	printf("-----ray-----\n");
	printf("camera_x: %f\n", ray->camera_x);
	printf("map.x: %d\n", ray->map.x);
	printf("map.y: %d\n", ray->map.y);
	printf("ray_dir.x: %f\n", ray->ray_dir.x);
	printf("ray_dir.y: %f\n", ray->ray_dir.y);
	printf("side_dist.x: %f\n", ray->side_dist.x);
	printf("side_dist.y: %f\n", ray->side_dist.y);
	printf("delta_dist.x: %f\n", ray->delta_dist.x);
	printf("delta_dist.y: %f\n", ray->delta_dist.y);
	printf("step_x: %d\n", ray->step.x);
	printf("step_y: %d\n", ray->step.y);
	printf("side_ns: %d\n", ray->side_ns);
	printf("perp_wall_dist: %f\n", ray->perp_wall_dist);
}

void	print_wall(t_wall *wall)
{
	printf("-----wall-----\n");
	printf("line_height: %d\n", wall->line_height);
	printf("draw_start: %d\n", wall->draw_start);
	printf("draw_end: %d\n", wall->draw_end);
	printf("tex.x: %d\n", wall->tex.x);
	printf("tex.y: %d\n", wall->tex.y);
	printf("wall_x: %f\n", wall->wall_x);
	printf("step: %f\n", wall->step);
	printf("tex_pos: %f\n", wall->tex_pos);
	printf("height_base: %f\n", wall->height_base);
	printf("color: %d\n", wall->color);
	printf("floor_color: %u\n", wall->floor_color);
	printf("ceiling_color: %u\n", wall->ceiling_color);
	printf("tex_img: %s\n", wall->tex_img->path);
}

void	print_copy(t_map *map, char **copy)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		printf("%s\n", copy[i]);
		i++;
	}
}

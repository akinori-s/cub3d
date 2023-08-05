/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:36:24 by shimakaori        #+#    #+#             */
/*   Updated: 2023/07/26 17:04:21 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_view_ns(t_player *player, t_map *map);
void	move_view_ew(t_player *player, t_map *map);
void	turn_view(t_player *player);
void	turn_vector(t_dvector *vec, double rad);

void	move_player(t_game *game)
{
	if (game->player.is_move_ns)
		move_view_ns(&game->player, &game->map);
	if (game->player.is_move_ew)
		move_view_ew(&game->player, &game->map);
	if (game->player.is_turning)
		turn_view(&game->player);
}

void	move_view_ns(t_player *player, t_map *map)
{
	t_dvector	new_pos;

	new_pos.x = player->pos.x + player->is_move_ns \
		* player->dir.x * PLAYER_MOVE_PX;
	if (new_pos.x < 0)
		new_pos.x = 0;
	if (map->map2d[(int)(player->pos.y)][(int)new_pos.x] != '1')
		player->pos.x = new_pos.x;
	new_pos.y = player->pos.y + player->is_move_ns \
		* player->dir.y * PLAYER_MOVE_PX;
	if (new_pos.y < 0)
		new_pos.y = 0;
	if (map->map2d[(int)new_pos.y][(int)(player->pos.x)] != '1')
		player->pos.y = new_pos.y;
}

void	move_view_ew(t_player *player, t_map *map)
{
	t_dvector	new_pos;
	t_dvector	perpendicular;

	perpendicular = player->dir;
	turn_vector(&perpendicular, M_PI / 2);
	new_pos.x = player->pos.x + player->is_move_ew \
		* perpendicular.x * PLAYER_MOVE_PX;
	if (new_pos.x < 0)
		new_pos.x = 0;
	if (map->map2d[(int)(player->pos.y)][(int)new_pos.x] != '1')
		player->pos.x = new_pos.x;
	new_pos.y = player->pos.y + player->is_move_ew \
		* perpendicular.y * PLAYER_MOVE_PX;
	if (new_pos.y < 0)
		new_pos.y = 0;
	if (map->map2d[(int)new_pos.y][(int)(player->pos.x)] != '1')
		player->pos.y = new_pos.y;
}

void	turn_view(t_player *player)
{
	double	rot_speed;

	rot_speed = player->is_turning * (M_PI / 200);
	turn_vector(&player->dir, rot_speed);
	turn_vector(&player->plane, rot_speed);
}

void	turn_vector(t_dvector *vec, double rad)
{
	t_dvector	tmp;

	tmp = *vec;
	vec->x = tmp.x * cos(rad) - tmp.y * sin(rad);
	vec->y = tmp.x * sin(rad) + tmp.y * cos(rad);
}

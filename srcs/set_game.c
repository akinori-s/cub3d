/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:15:01 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/05 00:22:11 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_gameinfo(char **map2d, t_map *map, t_player *player);
void	get_playerinfo(char c, t_player *player, size_t i, size_t j);
void	check_map(t_map *map, t_player *player);
void	read_background_color(t_map *map, t_wall *wall);

void	set_game(t_game *game, char *file)
{
	int		fd;
	char	*line;

	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		error_exit("Argument is not cubfile");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(strerror(errno));
	line = read_map_info(fd, game);
	if (line == NULL)
		error_exit("Map is not found");
	read_map(game, line, fd);
	close(fd);
	get_gameinfo(game->map.map2d, &game->map, &game->player);
	check_map(&game->map, &game->player);
	load_texture(game, &game->map);
	read_background_color(&game->map, &game->wall);
	set_screen(game, &game->img);
}

void	get_gameinfo(char **map2d, t_map *map, t_player *player)
{
	size_t	i;
	size_t	j;
	size_t	player_count;

	i = 0;
	player_count = 0;
	while (map2d[i] != NULL)
	{
		j = 0;
		while (map2d[i][j] != '\0')
		{
			if (is_news(map2d[i][j]))
			{
				get_playerinfo(map2d[i][j], player, i, j);
				player_count++;
			}
			else if (!is_chara(map2d[i][j]) && !is_news(map2d[i][j]))
				error_exit("Map has invalid character");
			j++;
		}
		i++;
	}
	if (player_count != 1)
		error_exit("Map has an invalid player count");
}

void	get_playerinfo(char c, t_player *player, size_t i, size_t j)
{
	player->pos.x = j + 0.5;
	player->pos.y = i + 0.5;
	if (c == 'N')
	{
		player->dir.y = -1;
		player->plane.x = 0.66;
	}
	else if (c == 'S')
	{
		player->dir.y = 1;
		player->plane.x = -0.66;
	}
	else if (c == 'W')
	{
		player->dir.x = -1;
		player->plane.y = -0.66;
	}
	else if (c == 'E')
	{
		player->dir.x = 1;
		player->plane.y = 0.66;
	}
	player->plane_len = sqrt(player->plane.x * player->plane.x \
		+ player->plane.y * player->plane.y);
}

void	check_map(t_map *map, t_player *player)
{
	if (map->height == 0 || map->width == 0)
		error_exit("Invalid map");
	else if (map->north_tex.path == NULL || map->south_tex.path == NULL \
		|| map->east_tex.path == NULL || map->west_tex.path == NULL \
		|| map->f_color == NULL || map->c_color == NULL)
		error_exit("Invalid texture path");
	else if (!check_texfile(map->north_tex.path) \
		|| !check_texfile(map->south_tex.path) \
		|| !check_texfile(map->east_tex.path) \
		|| !check_texfile(map->west_tex.path))
		error_exit("Texture is not xpmfile");
	else if (map->f_color == NULL || map->c_color == NULL)
		error_exit("Invalid color");
	if (!is_walled(map, player->pos.x, player->pos.y))
	{
		free_map(map);
		error_exit("map is not surrounded by wall");
	}
}

void	read_background_color(t_map *map, t_wall *wall)
{
	wall->ceiling_color = convert_color(map->c_color);
	wall->floor_color = convert_color(map->f_color);
}

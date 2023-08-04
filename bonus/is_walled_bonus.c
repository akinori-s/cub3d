/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_walled_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:03:46 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/04 23:58:08 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

bool	flood_check(t_map *map, char **copy, int x, int y);

bool	is_walled(t_map *map, int x, int y)
{
	char	**copy;
	size_t	i;
	bool	flag;

	i = 0;
	flag = false;
	copy = malloc(sizeof(char *) * map->height);
	if (!copy)
		error_exit("malloc failed");
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map2d[i]);
		if (!copy[i])
			error_exit("malloc failed in strdup");
		i++;
	}
	flag = flood_check(map, copy, x, y);
	i = 0;
	while (i < map->height)
		free(copy[i++]);
	free(copy);
	return (flag);
}

bool	flood_check(t_map *map, char **copy, int x, int y)
{
	if (copy[y][x] == '1' || copy[y][x] == 'F')
		return (true);
	else if (x <= 0 || x >= map->width || y <= 0 || y >= map->height \
		|| copy[y][x] == ' ' || copy[y][x] == '\0')
		return (false);
	copy[y][x] = 'F';
	return (flood_check(map, copy, x - 1, y)
		&& flood_check(map, copy, x + 1, y)
		&& flood_check(map, copy, x, y - 1)
		&& flood_check(map, copy, x, y + 1));
}

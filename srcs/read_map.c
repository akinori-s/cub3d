/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:03:59 by asasada           #+#    #+#             */
/*   Updated: 2023/07/30 17:02:23 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	pad_map(t_map *map)
{
	size_t	i;
	char	*pad;
	char	*tmp;

	i = 0;
	pad = ft_calloc(map->width + 1, sizeof(char));
	while (map->map2d[i] != NULL)
	{
		ft_bzero(pad, map->width);
		ft_memset(pad, ' ', map->width - ft_strlen(map->map2d[i]));
		tmp = map->map2d[i];
		map->map2d[i] = ft_strjoin(map->map2d[i], pad);
		free(tmp);
		if (map->map2d[i] == NULL)
			error_exit("Malloc failed at strjoin.");
		i++;
	}
	free(pad);
}

static size_t	max_row_width(char **map2d)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (map2d[i] != NULL)
	{
		if (ft_strlen(map2d[i]) > max)
			max = ft_strlen(map2d[i]);
		i++;
	}
	return (max);
}

int	read_map(t_game *game, char *next_line, int fd)
{
	char	*tmp;
	char	*flattened;

	flattened = NULL;
	while (next_line != NULL)
	{
		tmp = flattened;
		flattened = ft_strjoin(flattened, next_line);
		free(tmp);
		free(next_line);
		if (flattened == NULL)
			error_exit("Malloc failed at strjoin.");
		next_line = get_next_line(fd);
	}
	game->map.map2d = ft_split(flattened, '\n');
	free(flattened);
	if (game->map.map2d == NULL)
	{
		free_2darray(game->map.map2d);
		error_exit("Malloc failed at split.");
	}
	game->map.height = ft_2darray_len(game->map.map2d);
	game->map.width = max_row_width(game->map.map2d);
	pad_map(&game->map);
	return (0);
}

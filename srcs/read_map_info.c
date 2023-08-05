/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:03:58 by asasada           #+#    #+#             */
/*   Updated: 2023/08/03 00:24:57 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_map_info(char **info_ptr, char *line, char *specifier)
{
	char	*tmp1;

	if (*info_ptr != NULL)
		error_exit("Duplicate specifier.");
	tmp1 = ft_strtrim(line, specifier);
	if (tmp1 == NULL)
		error_exit("Malloc failed at strtrim.");
	*info_ptr = ft_strtrim(tmp1, " \n");
	if (*info_ptr == NULL)
		error_exit("Malloc failed at strtrim.");
	free(tmp1);
}

static bool	copy_mapinfo(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		set_map_info(&map->north_tex.path, line, "NO");
	else if (!ft_strncmp(line, "SO ", 3))
		set_map_info(&map->south_tex.path, line, "SO");
	else if (!ft_strncmp(line, "WE ", 3))
		set_map_info(&map->west_tex.path, line, "WE");
	else if (!ft_strncmp(line, "EA ", 3))
		set_map_info(&map->east_tex.path, line, "EA");
	else if (!ft_strncmp(line, "F ", 2))
		set_map_info(&map->f_color, line, "F");
	else if (!ft_strncmp(line, "C ", 2))
		set_map_info(&map->c_color, line, "C");
	else if ((is_char_iter(line, is_chara) || is_char_iter(line, is_news)) && \
		line[0] != '\n')
		return (true);
	else if (line[0] != '\n')
		error_exit("Invalid map info.");
	return (false);
}

char	*read_map_info(int fd, t_game *game)
{
	char	*line;
	int		i;
	bool	done;

	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		done = copy_mapinfo(&game->map, line);
		if (done)
			return (line);
		free(line);
		line = NULL;
	}
	return (NULL);
}

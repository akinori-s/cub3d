/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:26:15 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/03 23:26:44 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_screen(t_game *game, t_img *img, t_img *mini_img)
{
	img->image = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	mini_img->image = mlx_new_image(game->mlx, GRID_SIZE * MINIMAP_WIDTH, \
		GRID_SIZE* MINIMAP_WIDTH);
	if (img->image == NULL || mini_img->image == NULL)
		error_exit("Failed new image in set_screen");
	img->buffer = mlx_get_data_addr(img->image, &img->pixel_bits, \
		&img->line_bytes, &img->endian);
	mini_img->buffer = mlx_get_data_addr(mini_img->image, \
		&mini_img->pixel_bits, &mini_img->line_bytes, &mini_img->endian);
	if (img->buffer == NULL || mini_img->buffer == NULL)
		error_exit("Failed to get data addr in set_screen");
	
	img->width = SCREENWIDTH;
	img->height = SCREENHEIGHT;
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
		free(map->map2d[i++]);
	free(map->map2d);
	free(map->north_tex.path);
	free(map->south_tex.path);
	free(map->west_tex.path);
	free(map->east_tex.path);
	free(map->f_color);
	free(map->c_color);
}

void	free_2darray(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

size_t	ft_2darray_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	error_exit(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

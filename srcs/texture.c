/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:45:31 by shimakaori        #+#    #+#             */
/*   Updated: 2023/07/30 16:06:58 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_image(t_game *game, t_img *img);

void	load_texture(t_game *game, t_map *map)
{
	load_image(game, &map->north_tex);
	load_image(game, &map->south_tex);
	load_image(game, &map->east_tex);
	load_image(game, &map->west_tex);
}

void	load_image(t_game *game, t_img *img)
{
	img->image = mlx_xpm_file_to_image(game->mlx, img->path, \
		&img->width, &img->height);
	if (img->image == NULL)
		error_exit("Failed to file to image in load_image");
	img->buffer = mlx_get_data_addr(img->image, &img->pixel_bits, \
		&img->line_bytes, &img->endian);
	if (img->buffer == NULL)
		error_exit("Failed to get data addr in load_image");
}

uint32_t	convert_color(char *color)
{
	char	**rgb;
	size_t	r;
	size_t	g;
	size_t	b;
	size_t	i;

	i = 0;
	rgb = ft_split(color, ',');
	if (rgb == NULL)
		error_exit("Failed to split color.");
	while (rgb[i] != NULL)
		if (i++ >= 3)
			error_exit("Too many colors.");
	if (!is_digit_str(rgb[0]) || !is_digit_str(rgb[1]) || !is_digit_str(rgb[2])
		|| ft_strlen(rgb[0]) > 3 || ft_strlen(rgb[1]) > 3
		|| ft_strlen(rgb[2]) > 3)
		error_exit("Invalid color format.");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error_exit("Invalid color value.");
	free_2darray(rgb);
	return (r << 16 | g << 8 | b);
}

uint32_t	get_color(t_img img, int x, int y)
{
	return (*(uint32_t *)(img.buffer + \
		(y * img.line_bytes + x * (img.pixel_bits / 8))));
}

void	set_color(t_img *img, int x, int y, int color)
{
	char	*tmp;

	tmp = img->buffer + (y * img->line_bytes \
		+ x * (img->pixel_bits / 8));
	*(unsigned int *)tmp = color;
}

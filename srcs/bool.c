/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:23:36 by shimakaori        #+#    #+#             */
/*   Updated: 2023/07/30 15:56:51 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_texfile(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".xpm", 4))
		return (false);
	return (true);
}

bool	is_news(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	is_chara(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	return (false);
}

bool	is_digit_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

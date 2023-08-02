/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:23:36 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/03 00:16:19 by asasada          ###   ########.fr       */
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

bool	is_char_iter(char *str, bool (*f)(char))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!f(str[i]) && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

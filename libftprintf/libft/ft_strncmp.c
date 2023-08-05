/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:23:03 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:59 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned const char	*cs1;
	unsigned const char	*cs2;
	size_t				i;

	cs1 = (unsigned const char *)s1;
	cs2 = (unsigned const char *)s2;
	i = 0;
	if (size == 0)
		return (0);
	while (i < size - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (cs1[i] - cs2[i]);
}

// int	main(void)
// {
// 	char	s1[] = "";
// 	char	s2[] = "piscine";
// 	printf("%d\n", strncmp(s1, s2, 10));
// 	printf("%d\n", ft_strncmp(s1, s2, 10));

// 	char	t1[] = "piscine";
// 	char	t2[] = "";
// 	printf("%d\n", strncmp(t1, t2, 3));
// 	printf("%d\n", ft_strncmp(t1, t2, 3));

// 	char	y1[] = "hello";
// 	char	y2[] = "hello";
// 	printf("%d\n", strncmp(y1, y2, 0));
// 	printf("%d\n", ft_strncmp(y1, y2, 0));

// 	char	v1[] = "hello";
// 	char	v2[] = "hello";
// 	printf("%d\n", strncmp(v1, v2, 5));
// 	printf("%d\n", ft_strncmp(v1, v2, 5));
// }

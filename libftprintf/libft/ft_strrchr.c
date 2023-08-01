/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:23:20 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:38:05 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*tmp;

	cc = (char)c;
	tmp = (NULL);
	if (cc == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == cc)
			tmp = (char *)s;
		s++;
	}
	if (tmp == 0)
		return (NULL);
	return (tmp);
}

// void	display_result(char *results)
// {
// 	int		i;

// 	i = 0;
// 	while (*results != 0)
// 	{
// 		printf("%c", *results);
// 		i++;
// 		results++;
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	char	*test1 = strrchr("dabcdefghi", 'd');
// 	char	*test2 = ft_strrchr("dabcdefghi", 'd');
// 	char	*test3 = strrchr("abcd", 0);
// 	char	*test4 = ft_strrchr("abcd", 0);
// 	char	*test5 = strrchr("abcdefghi", '\0');
// 	char	*test6 = ft_strrchr("abcdefghi", '\0');
// 	display_result(test1);
// 	display_result(test2);
// 	display_result(test3);
// 	display_result(test4);
// 	display_result(test5);
// 	display_result(test6);
// }

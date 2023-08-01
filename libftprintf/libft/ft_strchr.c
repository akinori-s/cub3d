/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:11 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:36 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
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
// 	char	*test1 = strchr("abcdefghi", 'd');
// 	char	*test2 = ft_strchr("abcdefghi", 'd');
// 	char	*test3 = strchr("abcdefghi", 0);
// 	char	*test4 = ft_strchr("abcdefghi", 0);
// 	char	*test5 = strchr("abcdefghi", '\0');
// 	char	*test6 = ft_strchr("abcdefghi", '\0');
// 	char	*test7 = strchr("abczdefzghi", 'z');
// 	char	*test8 = ft_strchr("abczdefzghi", 'z');
//  char	*test9 = strchr("tripouille", 't' + 256);
// 	char	*test10 = ft_strchr("tripouille", 't' + 256);
// 	display_result(test1);
// 	display_result(test2);
// 	display_result(test3);
// 	display_result(test4);
// 	display_result(test5);
// 	display_result(test6);
// 	display_result(test7);
// 	display_result(test8);
// 	display_result(test9);
// 	display_result(test10);
// }

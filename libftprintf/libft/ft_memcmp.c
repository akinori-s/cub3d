/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:42 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:08 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	unsigned const char	*cs1;
	unsigned const char	*cs2;

	cs1 = (unsigned const char *)s1;
	cs2 = (unsigned const char *)s2;
	while (size)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
		size--;
	}
	return (0);
}

// int	main(void)
// {
// 	int	cmp;
// 	char	s1[] = "ab\0cdefg";
// 	char	s2[] = "hi\0jkomn";
// 	cmp = memcmp (s1, s2, 5);
// 	printf("%d\n", cmp);
// 	cmp = ft_memcmp (s1, s2, 5);
// 	printf("%d\n", cmp);
// 	char	s3[] = "abcdefg";
// 	char	s4[] = "abddefg";
// 	cmp = memcmp (s3, s4, 0);
// 	printf("%d\n", cmp);
// 	cmp = ft_memcmp (s3, s4, 0);
// 	printf("%d\n", cmp);
// 	char	*s5 = NULL;
// 	char	*s6 = NULL;
// 	cmp = memcmp (s5, s6, 5);
// 	printf("%d\n", cmp);
// 	cmp = ft_memcmp (s5, s6, 5);
// 	printf("%d\n", cmp);
// }

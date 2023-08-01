/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:32 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:05 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	unsigned const char	*cbuf;
	unsigned char		cc;
	size_t				i;

	cbuf = (unsigned const char *)buf;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cbuf[i] == cc)
			return ((void *)(&cbuf[i]));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*point;
// 	char	buf1[] = "abcdefg";
// 	point = memchr (&buf1, ' ', 10);
// 	printf("%s\n", point);

// 	char	buf2[] = "abcdefg";
// 	point = ft_memchr (&buf2, ' ', 10);
// 	printf("%s\n", point);

// 	char	buf3[] = "";
// 	point = memchr (&buf3, '\0', 10);
// 	printf("%s\n", point);

// 	char	buf4[] = "";
// 	point = ft_memchr (&buf4, '\0', 10);
// 	printf("%s\n", point);

// 	char *s = calloc(30, sizeof(char));
// 	memcpy(s, "libft-test-tokyo", 17);
// 	memcpy(s + 20, "acdfg", 5);
// 	point = memchr (s, '\0', 30);
// 	printf("%s\n", point);
// 	point = ft_memchr (s, '\0', 30);
// 	printf("%s\n", point);
// }

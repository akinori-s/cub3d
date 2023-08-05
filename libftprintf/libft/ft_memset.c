/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:21:13 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:18 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t size)
{
	unsigned char	*cbuf;
	unsigned char	cc;
	size_t			i;

	cbuf = (unsigned char *)buf;
	cc = (unsigned char)c;
	i = 0;
	while (i < size)
	{
		cbuf[i] = cc;
		i++;
	}
	return (buf);
}

// int	main(void)
// {
// 	char	buf1[] = "abcdefg";
// 	memset(buf1, 'k', 5);
// 	printf("%s\n", buf1);
// 	char	buf2[] = "abcdefg";
// 	ft_memset(&buf2, 'k', 5);
// 	printf("%s\n", buf2);

// 	char	buf3[] = "123456789";
// 	memset(buf3, '0', 3);
// 	printf("%s\n", buf3);
// 	char	buf4[] = "123456789";
// 	ft_memset(&buf4, '0', 3);
// 	printf("%s\n", buf4);
// }

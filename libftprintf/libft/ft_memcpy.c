/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:54 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:12 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cdst;
	unsigned char		*csrc;
	size_t				i;

	if (dst == src || n == 0)
		return (dst);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	dst1[] = "(NULL)";
// 	char	src1[] = "hijklmn";

// 	memcpy(dst1, src1, 0);
// 	printf("%s\n", dst1);
// 	char	dst2[] = "(NULL)";
// 	char	src2[] = "hijklmn";
// 	ft_memcpy(&dst2, &src2, 0);
// 	printf("%s\n", dst2);

// 	char	dst3[] = "";
// 	char	src3[] = "(NULL)";
// 	memcpy(dst3, src3, 0);
// 	printf("%s\n", dst3);

// 	char	dst4[] = "";
// 	char	src4[] = "(NULL)";
// 	ft_memcpy(&dst4, &src4, 0);
// 	printf("%s\n", dst4);
// }

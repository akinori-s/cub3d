/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:21:02 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:15 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (dst == src || size == 0)
		return (dst);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (cdst < csrc)
	{
		while (size--)
			*cdst++ = *csrc++;
	}
	else
	{
		cdst += size - 1;
		csrc += size - 1;
		while (size--)
			*cdst-- = *csrc--;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	dst1[] = "abcdefg";
// 	char	src1[] = "h\0ijklmn";

// 	memmove(dst1, src1, 5);
// 	printf("%s\n", dst1);
// 	char	dst2[] = "abcdefg";
// 	char	src2[] = "h\0ijklmn";
// 	ft_memmove(&dst2, &src2, 5);
// 	printf("%s\n", dst2);

// 	char	dst3[] = "12345";
// 	char	src3[] = "6789abcd";
// 	memmove(dst3, src3, 3);
// 	printf("%s\n", dst3);

// 	char	dst4[] = "12345";
// 	char	src4[] = "6789abcd";
// 	ft_memmove(&dst4, &src4, 3);
// 	printf("%s\n", dst4);
// }

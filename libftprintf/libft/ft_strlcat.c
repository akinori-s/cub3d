/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:34 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:47 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	src_len = ft_strlen(src);
	while (size != 0 && *dst != '\0')
	{
		dst++;
		size--;
		i++;
	}
	if (size == 0)
		return (i + src_len);
	while (*src != '\0' && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (i + src_len);
}

// int	main(void)
// {
// 	char	dst1[15] = "helloworld";
// 	char	src1[] = "12345";
// 	char	dst2[15] = "helloworld";
// 	char	src2[] = "12345";
// 	char	*dst3 = NULL;
// 	char	src3[] = "42tokyo";
// 	char	*dst4 =  NULL;
// 	char	src4[] = "42tokyo";
// 	size_t	len = 0;

// 	len = strlcat(dst1, src1, sizeof(dst1));
// 	printf("%zu\n", len);
// 	printf("%s\n", dst1);
// 	len = ft_strlcat(dst2, src2, sizeof(dst2));
// 	printf("%zu\n", len);
// 	printf("%s\n", dst2);
// 	len = strlcat(dst3, src3, 0);
// 	printf("%zu\n", len);
// 	printf("%s\n", dst3);
// 	len = ft_strlcat(dst4, src4, 0);
// 	printf("%zu\n", len);
// 	printf("%s\n", dst4);
// }

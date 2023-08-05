/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:41 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:50 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}

// int	main(void)
// {
// 	size_t		len = 0;
// 	char		dst[] = "";
// 	const char	src[] = "1234567890";

// 	len = strlcpy(dst, src, 0);
// 	printf("%zu\n", len);
// 	printf("%s\n", dst);
// 	len = ft_strlcpy(dst, src, 0);
// 	printf("%zu\n", len);
// 	printf("%s\n", dst);
// }

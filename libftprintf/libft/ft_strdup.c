/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:18 by shimakaori        #+#    #+#             */
/*   Updated: 2022/11/13 15:49:19 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*addr;
	size_t		len;

	len = ft_strlen(s);
	addr = (char *)ft_calloc((len + 1), sizeof(char));
	if (!addr)
		return (NULL);
	ft_memcpy(addr, s, len);
	return (addr);
}

// int	main(void)
// {
// 	char	src1[] = "";
// 	char	src2[] = "hello";
// 	char	src3[] = "hello world";
// 	char *str = malloc(1000);
// 	str = memset(str, 'A', 999);
// 	str[999] = '\0';

// 	printf("strdup    = %s\n", strdup(src1));
// 	printf("ft_strdup = %s\n", ft_strdup(src1));
// 	printf("%d\n", strcmp(strdup(src1), ft_strdup(src1)));
// 	printf("strdup    = %s\n", strdup(src2));
// 	printf("ft_strdup = %s\n", ft_strdup(src2));
// 	printf("%d\n", strcmp(strdup(src2), ft_strdup(src2)));
// 	printf("strdup    = %s\n", strdup(src3));
// 	printf("ft_strdup = %s\n", ft_strdup(src3));
// 	printf("%d\n", strcmp(strdup(src3), ft_strdup(src3)));
// 	printf("strdup    = %s\n", strdup(str));
// 	printf("ft_strdup = %s\n", ft_strdup(str));
// 	printf("%d\n", strcmp(strdup(str), ft_strdup(str)));
// }

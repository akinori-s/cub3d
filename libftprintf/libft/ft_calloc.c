/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:19:09 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/01 21:34:38 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*numsize;

	if (num == 0 || size == 0)
		return (ft_calloc(1, 1));
	else if (num > (SIZE_MAX / size) || size > (SIZE_MAX / num))
		return (NULL);
	else
	{
		numsize = (void *)malloc(num * size);
		if (!numsize)
			return (NULL);
		ft_memset(numsize, 0, num * size);
		return (numsize);
	}
}

// int	main(void)
// {
// 	char			*ptr1;
// 	char			*ptr2;
// 	unsigned long	num;
// 	unsigned long	size;

// 	num = (size_t)SIZE_MAX / 10 + (size_t)1;
// 	size = 10;
// 	ptr1 = (char *)calloc(num, size);
// 	ptr2 = (char *)ft_calloc(num, size);
// 	printf("SIZE_MAX  = %lu\n", SIZE_MAX);
// 	printf("num       = %lu\n", num);
// 	printf("size      = %lu\n", size);
// 	printf("numsize   = %lu\n", (num * size));
// 	printf("calloc    = %s\n", ptr1);
// 	printf("ft_calloc = %s\n", ptr2);
// 	free(ptr1);
// 	free(ptr2);
// }

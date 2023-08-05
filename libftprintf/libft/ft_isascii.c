/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:19:45 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:26 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;
// 	for (i = 0; i < UCHAR_MAX; i++)
// 	{
// 		if (isascii(i))
// 			printf("isascii =    %c\n", i);
// 		if (ft_isascii(i))
// 			printf("ft_isascii = %c\n", i);
// 	}
// }

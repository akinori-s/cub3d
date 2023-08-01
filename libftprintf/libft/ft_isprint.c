/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:05 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:32 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;
// 	for (i = 0; i < UCHAR_MAX; i++)
// 	{
// 		if (isprint(i))
// 			printf("isprint =    %c\n", i);
// 		if (ft_isprint(i))
// 			printf("ft_isprint = %c\n", i);
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:19:55 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:29 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;
// 	for (i = 0; i < UCHAR_MAX; i++)
// 	{
// 		if (isdigit(i))
// 			printf("isdigit =    %c\n", i);
// 		if (ft_isdigit(i))
// 			printf("ft_isdigit = %c\n", i);
// 	}
// }

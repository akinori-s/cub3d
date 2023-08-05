/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:19:22 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 14:31:10 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;
// 	for (i = 0; i < UCHAR_MAX; i++)
// 	{
// 		if (isalnum(i))
// 			printf("isalnum =    %c\n", i);
// 		if (ft_isalnum(i))
// 			printf("ft_isalnum = %c\n", i);
// 	}
// }

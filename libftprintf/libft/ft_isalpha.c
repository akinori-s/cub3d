/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:19:34 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 14:31:14 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}

// int main(void)
// {
// 	int i;
// 	for (i = 0; i < UCHAR_MAX; i++)
// 	{
// 		if (isalpha(i))
// 			printf("isapha =     %c\n", i);

// 		if (ft_isalpha(i))
// 			printf("ft_isalpha = %c\n", i);
// 	}
// }

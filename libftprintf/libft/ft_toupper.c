/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:26:13 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:38:16 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

// int	main(void)
// {
//     int	c1 = 'a';
// 	int	c2 = 'a';

// 	c1 = toupper(c1);
// 	printf("%c\n", c1);
//     c2 = ft_toupper(c2);
//     printf("%c\n", c2);
// }

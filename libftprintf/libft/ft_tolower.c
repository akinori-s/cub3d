/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:39:56 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:38:13 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

// int	main(void)
// {
//     int	c1 = 'A';
// 	int	c2 = 'A';

// 	c1 = tolower(c1);
//     printf("%c\n", c1);
//     c2 = ft_tolower(c2);
//     printf("%c\n", c2);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:48 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:53 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

// int	main(void)
// {
// 	char	a[] = "helloworld";
// 	int	n = strlen(a);
// 	printf("%d\n", n);
// 	n = ft_strlen(a);
// 	printf("%d\n", n);
// 	char	b[] = "";
// 	int	m = strlen(b);
// 	printf("%d\n", m);
// 	m = ft_strlen(b);
// 	printf("%d\n", m);

// 	char	*c = NULL;
// 	int	l = strlen(c);
// 	printf("%d\n", l);
// 	l = ft_strlen(c);
// 	printf("%d\n", l);
// }

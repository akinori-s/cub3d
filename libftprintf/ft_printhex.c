/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:08:59 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/11 10:23:53 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n);

int	ft_printhex(unsigned int n, int format)
{
	int	len;

	len = 0;
	if (n == 0)
		return (ft_printchar('0'));
	len = ft_hexlen(n);
	if (n >= 16)
	{
		ft_printhex(n / 16, format);
		ft_printhex(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_printchar(n + '0');
		else
		{
			if (format == 'x')
				ft_printchar(n - 10 + 'a');
			if (format == 'X')
				ft_printchar(n - 10 + 'A');
		}
	}
	return (len);
}

static int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

// int	main(void)
// {
// 	int			len;
// 	const char	format = 'x';

// 	len = 0;
// 	printf("%x\n", 42);
// 	len = ft_printhex(42, format);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	printf("%x\n", -42);
// 	len = ft_printhex(-42, format);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	printf("%x\n", 0);
// 	len = ft_printhex(0, format);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	printf("%x\n", 2147483647);
// 	len = ft_printhex(2147483647, format);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// }

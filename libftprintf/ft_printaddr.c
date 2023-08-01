/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:20:41 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/14 11:02:09 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointlen(unsigned long long point);
int			ft_putpoint(unsigned long long point);

int	ft_printaddr(unsigned long long point)
{
	int			len;

	len = 0;
	len += ft_printstr("0x");
	len += ft_putpoint(point);
	return (len);
}

static int	ft_pointlen(unsigned long long point)
{
	int	len;

	len = 0;
	while (point)
	{
		point = point / 16;
		len++;
	}
	return (len);
}

int	ft_putpoint(unsigned long long point)
{
	int	len;

	len = 0;
	if (point == 0)
		return (ft_printchar('0'));
	len = ft_pointlen(point);
	if (point >= 16)
	{
		ft_putpoint(point / 16);
		ft_putpoint(point % 16);
	}
	else
	{
		if (point < 10)
			ft_printchar(point + '0');
		else
			ft_printchar(point - 10 + 'a');
	}
	return (len);
}

// int	main(void)
// {
// 	int	num = 42;
// 	int	*p = &num;

// 	printf("%p\n", p);
// 	ft_printf("%p\n", p);
//	}

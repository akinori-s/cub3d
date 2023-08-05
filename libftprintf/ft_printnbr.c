/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:58:45 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/19 13:22:29 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

// int	main(void)
// {
// 	int	len;

// 	len = 0;
// 	len = ft_printnbr(42);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	len = ft_printnbr(-42);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	len = ft_printnbr(0);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	len = ft_printnbr(2147483647);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	len = ft_printnbr(-2147483648);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:03:01 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/19 13:22:18 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_digit(unsigned int n);
static void		put_num(char *str, unsigned int n, size_t digit);
static char		*ft_itoa_unsigned(unsigned int n);

int	ft_printnbr_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa_unsigned(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

static size_t	get_digit(unsigned int n)
{
	size_t	digit;

	digit = 0;
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	put_num(char *str, unsigned int n, size_t digit)
{	
	while (digit > 0)
	{
		str[digit - 1] = n % 10 + '0';
		n /= 10;
		digit--;
	}
	return ;
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	size_t	digit;

	str = NULL;
	digit = 0;
	if (n == 0)
		return (ft_strdup("0"));
	digit = get_digit(n);
	str = (char *)ft_calloc((digit + 1), sizeof(char));
	if (!str)
		return (NULL);
	put_num(str, n, digit);
	return (str);
}

// int	main(void)
// {
// 	int	len;

// 	len = 0;
// 	printf("%u\n", 42);
// 	len = ft_printnbr_unsigned(42);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	printf("%u\n", 0);
// 	len = ft_printnbr_unsigned(0);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	printf("%u\n", 2147483647);
// 	len = ft_printnbr_unsigned(2147483647);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// 	printf("%u\n", -2147483647);
// 	len = ft_printnbr_unsigned(-2147483647);
// 	printf("\n");
// 	printf("len = %d", len);
// 	printf("\n");
// }

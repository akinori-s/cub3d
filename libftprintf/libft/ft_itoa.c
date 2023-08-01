/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:16 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:34 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(unsigned int num);
static void	put_num(char *str, unsigned int num, int sign);

char	*ft_itoa(int n)
{
	char				*str;
	int					sign;
	unsigned int		num;

	sign = 0;
	num = 0;
	str = NULL;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
	{
		sign = 1;
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	str = (char *)ft_calloc((get_digit(num) + sign + 1), sizeof(char));
	if (!str)
		return (NULL);
	put_num(str, num, sign);
	return (str);
}

static int	get_digit(unsigned int num)
{
	int	digit;

	digit = 0;
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

static void	put_num(char *str, unsigned int num, int sign)
{	
	int		digit;

	digit = 0;
	digit = get_digit(num);
	if (sign == 1)
	{
		*str = '-';
		str++;
	}
	while (digit > 0)
	{
		str[digit - 1] = num % 10 + '0';
		num /= 10;
		digit--;
	}
	return ;
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-0));
// 	printf("%s\n", ft_itoa(+0));
// }

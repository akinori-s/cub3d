/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:18:38 by shimakaori        #+#    #+#             */
/*   Updated: 2022/09/20 17:11:56 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num(char const *str, int flag);
static int	my_isspace(int c);

int	ft_atoi(const char *str)
{
	int		flag;
	int		num;
	size_t	i;

	flag = 1;
	num = 0;
	i = 0;
	if (!str)
		return (0);
	while (my_isspace((int)str[i]))
		i++;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	num = get_num(&str[i], flag);
	return (num);
}

static int	get_num(char const *str, int flag)
{
	unsigned long long	num;
	size_t				i;

	num = 0;
	i = 0;
	while ((str[i] - '0') == 0)
		i++;
	while (ft_isdigit(str[i]))
	{
		if (flag == -1 && num > (LONG_MAX / 10))
			return ((int)LONG_MIN);
		if (flag == 1 && num > (LONG_MAX / 10))
			return ((int)LONG_MAX);
		num = num * 10 + (str[i++] - '0');
		if (flag == -1 && (num - 1) > LONG_MAX)
			return ((int)LONG_MIN);
		if (flag == 1 && num > LONG_MAX)
			return ((int)LONG_MAX);
	}
	return ((int)(num * flag));
}

static int	my_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("LLONG_MAX =  %lld\n", LLONG_MAX);
// 	printf("LLONG_Min = %lld\n", LLONG_MIN);
// 	printf("LONG_MAX =   %ld\n", LONG_MAX);
// 	printf("LONG_Min =  %ld\n", LONG_MIN);
// 	printf("INT_MAX =    %d\n", INT_MAX);
// 	printf("INT_MIN =   %d\n", INT_MIN);
// 	printf("UINT_MAX =    %u\n", UINT_MAX);
// 	printf("ULONG_MAX =  %lu\n", ULONG_MAX);
// 	printf("SIZE_MAX =   %lu\n", SIZE_MAX);
// 	printf("atoi  : ft_atoi\n");
// 	printf("[LONG_MAX + 1]%d : ", atoi("9223372036854775808"));
// 	printf("%d\n", ft_atoi("9223372036854775808"));
// 	printf("[LONG_MIN - 1]%d : ", atoi("-9223372036854775808"));
// 	printf("%d\n", ft_atoi("-9223372036854775809"));
// 	printf("[LONG_MAX]%d : ", atoi("9223372036854775807"));
// 	printf("%d\n", ft_atoi("9223372036854775807"));
// 	printf("[LONG_MIN]%d : ", atoi("-9223372036854775808"));
// 	printf("%d\n", ft_atoi("-9223372036854775808"));
// 	printf("[INT_MAX]%d : ", atoi("2147483647"));
// 	printf("%d\n", ft_atoi("2147483647"));
// 	printf("[INT_MIN]%d : ", atoi("-2147483648"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("[INT_MAX + 1]%d : ", atoi("2147483648"));
// 	printf("%d\n", ft_atoi("2147483648"));
// 	printf("[INT_MIN - 1]%d : ", atoi("-2147483649"));
// 	printf("%d\n", ft_atoi("-2147483649"));
// 	printf("[UINT_MAX]%d : ", atoi("4294967295"));
// 	printf("%d\n", ft_atoi("4294967295"));
// 	printf("[UINT_MAX + 1]%d : ", atoi("4294967296"));
// 	printf("%d\n", ft_atoi("4294967296"));
// 	printf("[UINT_MAX - 1]%d : ", atoi("4294967294"));
// 	printf("%d\n", ft_atoi("4294967294"));
// 	printf("[ULONG_MAX + 1]%d : ", atoi("18446744073709551616"));
// 	printf("%d\n", ft_atoi("18446744073709551616"));
// 	printf("[LONG_MAX - 1]%d : ", atoi("9223372036854775806"));
// 	printf("%d\n", ft_atoi("9223372036854775806"));
// 	printf("[ULONG_MIN + 1]%d : ", atoi("-9223372036854775807"));
// 	printf("%d\n", ft_atoi("-9223372036854775807"));
// 	printf("[-0]%d : ", atoi("-0"));
// 	printf("%d\n", ft_atoi("-0"));
// 	printf("[manyzero]%d : ", atoi("000000000000000000008"));
// 	printf("%d\n", ft_atoi("000000000000000000008"));

// 	char str1[] = "-99999999999999999999999999";
// 	printf("%s : %d : %d\n", str1, atoi(str1), ft_atoi(str1));
// 	char str2[] = "-000000000000000000008";
// 	printf("%s : %d : %d\n", str2, atoi(str2), ft_atoi(str2));
// }

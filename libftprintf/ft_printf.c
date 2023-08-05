/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:50:59 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/14 12:21:51 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(va_list	ap, int format);

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!format)
		return (ERROR);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += check_type(ap, (int)format[i]);
		}
		else
			count += ft_printchar((int)format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

static int	check_type(va_list	ap, int format)
{
	size_t	length;

	length = 0;
	if (format == 'c')
		length = ft_printchar(va_arg(ap, int));
	else if (format == 's')
		length = ft_printstr(va_arg(ap, char *));
	else if (format == 'p')
		length = ft_printaddr((unsigned long long)va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		length = ft_printnbr(va_arg(ap, int));
	else if (format == 'u')
		length = ft_printnbr_unsigned(va_arg(ap, unsigned long long));
	else if (format == 'x' || format == 'X')
		length = ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		length = ft_printchar('%');
	return (length);
}

// int	main(void)
// {
// 	int	num = 42;
// 	int	*p = &num;

// 	printf("%p\n", p);
// 	ft_printf("%p\n", p);
// }

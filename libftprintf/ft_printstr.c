/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:48:56 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/14 10:45:34 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

// int	main(void)
// {
// 	int		len;
// 	char	*a;

// 	len = 0;
// 	a = "-42";
// 	len = ft_printstr(a);
// 	printf("\n");
// 	printf("%d", len);

// 	a = NULL;
// 	len = ft_printstr(a);
// 	printf("\n");
// 	printf("%d", len);
// }

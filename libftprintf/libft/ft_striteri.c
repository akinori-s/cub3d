/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:41:39 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:41 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void	ft_test(unsigned int num, char *c)
// {
// 	*c -= 32;
// 	printf ("[%d] = %c\n", num, *c);
// }

// int	main(void)
// {
// 	char	s[] = "abcdefghijk";

// 	ft_striteri(s, &ft_test);
// }

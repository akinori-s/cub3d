/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:54 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:57 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	return (result);
}

// char	ft_test(unsigned int num, char str)
// {
// 	str -= 32;
// 	printf ("[%d] = %c\n", num, str);
// 	return (0);
// }

// int	main(void)
// {
// 	char const	str[] = "abcdefghijk";

// 	ft_strmapi(str, &ft_test);
// }

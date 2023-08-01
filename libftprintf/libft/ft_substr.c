/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:51:35 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:38:10 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		sub = (char *)ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	else
		sub = (char *)ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	while (len && s[start])
	{
		sub[i++] = (char)s[start++];
		len--;
	}
	return (sub);
}

// int	main(void)
// {
// 	char	s1[] = "helloworld";

// 	printf("%s\n", ft_substr(s1, 5, 3));
// 	printf("%s\n", ft_substr(s1, 9, 5));
// 	printf("%s\n", ft_substr("tripouille", 0, 42000));
// 	printf("%s\n", ft_substr("0123456789", 9, 10));
// 	printf("%s\n", ft_substr(s1, 11, 0));
// 	printf("%s\n", ft_substr(NULL, 5, 3));
// }

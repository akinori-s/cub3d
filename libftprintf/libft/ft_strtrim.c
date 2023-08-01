/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:23:28 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:38:07 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	trim = ft_substr(s1, 0, (len + 1));
	return (trim);
}

// int	main(void)
// {
// 	char const	s1[] = "1hello2world34";
// 	char const	set1[] = "";
// 	char const	s2[] = "	42piscine42piscne 42";
// 	char const	set2[] = "\t42";

// 	printf("%s\n", ft_strtrim(s1, set1));
// 	printf("%s\n", ft_strtrim(s2, set2));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:26 by shimakaori        #+#    #+#             */
/*   Updated: 2023/07/30 14:32:55 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (SIZE_MAX - s1_len < s2_len + 1)
		return (NULL);
	joined = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, s1_len + 1);
	ft_strlcat(joined, s2, s1_len + s2_len + 1);
	return (joined);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*result;
// 	size_t	length;
// 	size_t	i;
// 	size_t	j;

// 	length = 0;
// 	i = 0;
// 	j = 0;
// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	length = (ft_strlen(s1)) + (ft_strlen(s2));
// 	result = (char *)malloc((length + 1) * sizeof(char));
// 	if (!result)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		result[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 		result[i++] = s2[j++];
// 	result[i] = '\0';
// 	return (result);
// }

// int	main(void)
// {
// 	char	s1[] = "hello";
// 	char	s2[] = "world";

// 	printf("%s\n", ft_strjoin(s1, s2));
// }

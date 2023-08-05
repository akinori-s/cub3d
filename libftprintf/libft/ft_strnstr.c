/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:23:13 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:38:02 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0 || len < needle_len)
		return (NULL);
	while (haystack[i] != '\0' && i + needle_len <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (!(ft_strncmp(&haystack[i], &needle[0], needle_len)))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {	
// 	int i = 3;
// 	char *test1 = NULL;
// 	const char haystack1[] = "libft-test-tokyo";
// 	const char needle1[] = "";
// 	printf("test1\n");
// 	test1 = ft_strnstr(((void *)0), "fake", 3);
// 	printf("ft_strnstr = %s\n", test1);
// 	test1 = strnstr(((void *)0), "fake", 3);
// 	printf("strnstr    = %s\n", test1);
// char *test2 = NULL;
// const char haystack2[] = "libft-test-tokyo";
// const char needle2[] = "libft-test-tokyo";
// test2 = strnstr(haystack2, needle2, i);
// printf("test2\n");
// printf("strnstr    = %s\n", test2);
// test2 = ft_strnstr(haystack2, needle2, i);
// printf("ft_strnstr = %s\n", test2);
// char *test3 = NULL;
// const char haystack3[] = "libft-test-tokyo";
// const char needle3[] = "libft";
// test3 = strnstr(haystack3, needle3, i);
// printf("test3\n");
// printf("strnstr    = %s\n", test3);
// test3 = ft_strnstr(haystack3, needle3, i);
// printf("ft_strnstr = %s\n", test3);
// char *test4 = NULL;
// const char haystack4[] = "libft-test-tokyo";
// const char *needle4 = "test";
// test4 = strnstr(haystack4, needle4, i);
// printf("test4\n");
// printf("strnstr    = %s\n", test4);
// test4 = ft_strnstr(haystack4, needle4, i);
// printf("ft_strnstr = %s\n", test4);
// char *test5 = NULL;
// const char haystack5[] = "libft-test-tokyo";
// const char needle5[] = "tokyo";
// test5 = strnstr(haystack5, needle5, i);
// printf("test5\n");
// printf("strnstr    = %s\n", test5);
// test5 = ft_strnstr(haystack5, needle5, i);
// printf("ft_strnstr = %s\n", test5);
// char *test6 = NULL;
// const char haystack6[] = "libft-test-tokyo";
// const char needle6[] = "libft~";
// test6 = strnstr(haystack6, needle6, i);
// printf("test6\n");
// printf("strnstr    = %s\n", test6);
// test6 = ft_strnstr(haystack6, needle6, i);
// printf("ft_strnstr = %s\n", test6);
// char *test7 = NULL;
// const char haystack7[] = "libft-test-tokyo";
// const char needle7[] = "z";
// test7 = strnstr(haystack7, needle7, i);
// printf("test7\n");
// printf("strnstr    = %s\n", test7);
// test7 = ft_strnstr(haystack7, needle7, i);
// printf("ft_strnstr = %s\n", test7);
// }
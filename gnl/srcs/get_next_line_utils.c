/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:52:42 by shimakaori        #+#    #+#             */
/*   Updated: 2022/11/09 11:11:41 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *s, int c);
char	*gnl_calloc(size_t num, size_t size);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(char *s1, char *s2);

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*gnl_calloc(size_t num, size_t size)
{
	char	*numsize;
	size_t	i;

	i = 0;
	if (num == 0 || size == 0)
		return (gnl_calloc(1, 1));
	else if (num > (SIZE_MAX / size) || size > (SIZE_MAX / num))
		return (NULL);
	else
	{
		numsize = (void *)malloc(num * size);
		if (!numsize)
			return (NULL);
		while (i < num * size)
		{
			numsize[i] = '\0';
			i++;
		}
		return (numsize);
	}
}

char	*gnl_strdup(const char *s)
{
	char		*addr;
	size_t		len;
	size_t		i;

	if (!s)
		return (NULL);
	len = gnl_strlen(s);
	addr = gnl_calloc((len + 1), sizeof(char));
	if (!addr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		addr[i] = s[i];
		i++;
	}
	return (addr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	length;
	size_t	i;
	size_t	j;

	length = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	length = (gnl_strlen(s1)) + (gnl_strlen(s2));
	result = gnl_calloc((length + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	free(s1);
	return (result);
}

// int	main(void)
// {
// 	char	s1[] = "hello";
// 	char	s2[] = "world";

// 	printf("%s\n", gnl_strjoin(s1, s2));

// 	char	src1[] = "";
// 	char	src2[] = "hello";
// 	char	src3[] = "hello world";
// 	char *str = malloc(1000);
// 	str = memset(str, 'A', 999);
// 	str[999] = '\0';

// 	printf("strdup    = %s\n", strdup(src1));
// 	printf("gnl_strdup = %s\n", gnl_strdup(src1));
// 	printf("%d\n", strcmp(strdup(src1), gnl_strdup(src1)));
// 	printf("strdup    = %s\n", strdup(src2));
// 	printf("gnl_strdup = %s\n", gnl_strdup(src2));
// 	printf("%d\n", strcmp(strdup(src2), gnl_strdup(src2)));
// 	printf("strdup    = %s\n", strdup(src3));
// 	printf("gnl_strdup = %s\n", gnl_strdup(src3));
// 	printf("%d\n", strcmp(strdup(src3), gnl_strdup(src3)));
// 	printf("strdup    = %s\n", strdup(str));
// 	printf("gnl_strdup = %s\n", gnl_strdup(str));
// 	printf("%d\n", strcmp(strdup(str), gnl_strdup(str)));
// }

// void	display_result(char *results)
// {
// 	int		i;

// 	i = 0;
// 	while (*results != 0)
// 	{
// 		printf("%c", *results);
// 		i++;
// 		results++;
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	char	*test1 = strchr("abcdefghi", 'd');
// 	char	*test2 = gnl_strchr("abcdefghi", 'd');
// 	char	*test3 = strchr("abcdefghi", 0);
// 	char	*test4 = gnl_strchr("abcdefghi", 0);
// 	char	*test5 = strchr("abcdefghi", '\0');
// 	char	*test6 = gnl_strchr("abcdefghi", '\0');
// 	char	*test7 = strchr("abczdefzghi", 'z');
// 	char	*test8 = gnl_strchr("abczdefzghi", 'z');
//  	char	*test9 = strchr("tripouille", 't' + 256);
// 	char	*test10 = gnl_strchr("tripouille", 't' + 256);
// 	display_result(test1);
// 	display_result(test2);
// 	display_result(test3);
// 	display_result(test4);
// 	display_result(test5);
// 	display_result(test6);
// 	display_result(test7);
// 	display_result(test8);
// 	display_result(test9);
// 	display_result(test10);
// }

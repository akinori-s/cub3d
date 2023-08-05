/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:22:03 by shimakaori        #+#    #+#             */
/*   Updated: 2023/07/30 16:58:55 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strddup(char *src, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	int	split_len(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count += 1;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**freedom(char **ptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((split_len(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			ptr[j] = ft_strddup((char *)(s + i), c);
			if (!ptr[j])
				return (freedom(ptr, j));
			i += ft_strlen(ptr[j++]);
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

// void	display_result(char **results)
// {
// 	int		i;

// 	i = 0;
// 	while (*results != 0)
// 	{
// 		printf("tab[%d]: %s\n", i, *results);
// 		i++;
// 		results++;
// 	}
// 	printf("--------------------------------\n");
// }

// int	main(void)
// {
// 	char const	*s1 = "abc def ghi";
// 	char		c1 = ' ';
// 	char		**test1 = ft_split(s1, c1);

// 	char const	*s2 = "zabczabczabcz";
// 	char		c2 = 'z';
// 	char		**test2 = ft_split(s2, c2);

// 	char const	*s3 = "abcdefghijk";
// 	char		c3 = 'z';
// 	char		**test3 = ft_split(s3, c3);

// 	char const	*s4 = "ab";
// 	char		c4 = 'a';
// 	char		**test4 = ft_split(s4, c4);

// 	char const	*s5 = "tripouille";
// 	char		c5 = 0;
// 	char		**test5 = ft_split(s5, c5);

// 	char		**test6 = ft_split("\0aa\0bbb", '\0');
// 	char		**test7 = ft_split("      ", ' ');
// 	//char		**test8 = ft_split(NULL, 'a');

// 	display_result(test1);
// 	display_result(test2);
// 	display_result(test3);
// 	display_result(test4);
// 	display_result(test5);
// 	display_result(test6);
// 	display_result(test7);
// 	//display_result(test8);
// 	system("leaks a.out");
// 	return (0);
// }

// #include <string.h>
// #include <xlocale.h>
// #include <stdio.h>
// #include <assert.h> 

// void	print_and_free(char **a)
// {
// 	int		i;

// 	if (a != NULL)
// 	{
// 		i = 0;
// 		while (a[i] != NULL)
// 		{
// 			printf("  %s\n", a[i]);
// 			free(a[i++]);
// 		}
// 	}
// 	free(a);
// 	printf("  ---free completed---\n");
// }

// int	testmain_split(void)
// {
// 	char	**a;

// 	a = ft_split("hello world", ' ');
// 	assert(!strcmp(a[0], "hello"));
// 	assert(!strcmp(a[1], "world"));
// 	print_and_free(a);

// 	a = ft_split("abcdaba", 'a');
// 	assert(!strcmp(a[0], "bcd"));
// 	assert(!strcmp(a[1], "b"));
// 	print_and_free(a);

// 	a = ft_split("abcdaba", '\0');
// 	assert(!strcmp(a[0], "abcdaba"));
// 	print_and_free(a);

// 	a = ft_split("", 'a');
// 	assert(*a == NULL);
// 	print_and_free(a);

// 	a = ft_split(NULL, 'a');//error
// 	assert(a == NULL);
// 	//printf("  a = %p\n ", a); 
// 	// fflush(stdout);
// 	// printf(" *a = %p\n ", a[0]);
// 	// fflush(stdout);
// 	// printf("**a = %c\n ", a[0][0]);
// 	// fflush(stdout);
// 	print_and_free(a);

// 	a = ft_split("      ", ' ');
// 	assert(*a == NULL);
// 	print_and_free(a);

// 	a = ft_split("\0aa\0bbb", '\0');
// 	assert(*a == NULL);
// 	print_and_free(a);

// 	return (0);
// }

// int	main(void)
// {
// 	testmain_split();

// 	system("leaks a.out");
// 	return (0);
// }

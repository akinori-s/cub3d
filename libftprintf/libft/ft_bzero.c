/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:18:55 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 14:31:03 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int	main(void)
// {
// 	int i;
// 	char s[] = "abcdefghijklmnopqrstuvwxyz";
// 	printf("s = %s\n", s);
// 	bzero(&s, 3);
// 	printf("s = ");
// 	for (i = 0; i < 26; i++)
// 		printf("%c", s[i]);
// 	printf("\n");
// 	char t[] = "abcdefghijklmnopqrstuvwxyz";
// 	printf("t = %s\n", t);
// 	ft_bzero(&t, 3);
// 	printf("t = ");
// 	for (i = 0; i < 26; i++)
// 		printf("%c", t[i]);
// 	printf("\n");
// }

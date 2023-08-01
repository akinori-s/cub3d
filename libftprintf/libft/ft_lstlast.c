/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:55:39 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:53 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	char	str1[] = "abcdefg";
// 	char	str2[] = "hijklmn";
// 	char	str3[] = "opqrstu";
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 	t_list	*test;

// 	lst1 = ft_lstnew(str1);
// 	lst2 = ft_lstnew(str2);
// 	lst3 = ft_lstnew(str3);
// 	ft_lstadd_front(&lst1, lst2);
// 	ft_lstadd_front(&lst1, lst3);
// 	printf("%s\n", (char *)lst1->content);
// 	test = ft_lstlast(lst1);
// 	printf("%s\n", (char *)test->content);
// }

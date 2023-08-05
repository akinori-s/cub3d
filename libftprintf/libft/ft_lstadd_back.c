/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:05:51 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:39 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
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
// 	ft_lstadd_back(&lst1, lst2);
// 	ft_lstadd_back(&lst1, lst3);
// 	printf("%s\n", (char *)lst1->content);
// 	printf("%s\n", (char *)lst1->next->content);
// 	test = ft_lstlast(lst1);
// 	printf("%s\n", (char *)test->content);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:54 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:44 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp, del);
	}
	*lst = (NULL);
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	char	str1[] = "abcdefg";
// 	char	str2[] = "hijklmn";
// 	char	str3[] = "opqrstu";
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*lst3;

// 	lst1 = ft_lstnew(str1);
// 	lst2 = ft_lstnew(str2);
// 	lst3 = ft_lstnew(str3);
// 	ft_lstadd_back(&lst1, lst2);
// 	ft_lstadd_back(&lst1, lst3);
// 	printf("%s\n", (char *)lst1->content);
// 	printf("%s\n", (char *)lst1->next->content);
// 	printf("%s\n", (char *)lst1->next->next->content);
// 	printf("%p\n", &lst1);
// 	ft_lstclear(&lst1, &del);
// 	printf("%p\n", &lst1);
// 	printf("%s\n", (char *)lst1->content);
// }

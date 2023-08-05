/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:50:31 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:56 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	tmp = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!(new_lst))
		{
			ft_lstclear(&tmp, (*del));
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = (NULL);
	return (tmp);
}

// void	*f(void *content)
// {
// 	return (content);
// }

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
// 	t_list	*test;

// 	lst1 = ft_lstnew(str1);
// 	lst2 = ft_lstnew(str2);
// 	lst3 = ft_lstnew(str3);
// 	ft_lstadd_back(&lst1, lst2);
// 	ft_lstadd_back(&lst1, lst3);
// 	printf("%s\n", (char *)lst1->content);
// 	printf("%s\n", (char *)lst1->next->content);
// 	printf("%s\n", (char *)lst1->next->next->content);
// 	test = ft_lstmap(lst1, &f, &del);
// 	printf("%s\n", (char *)test->content);
// 	printf("%s\n", (char *)test->next->content);
// 	printf("%s\n", (char *)test->next->next->content);
// }

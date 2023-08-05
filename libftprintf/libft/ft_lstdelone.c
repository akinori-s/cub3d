/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:17:20 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:36:47 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	char	str1[] = "abcdefg";
// 	char	str2[] = "hijklmn";
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*tmp;

// 	lst1 = ft_lstnew(ft_strdup(str1));
// 	lst2 = ft_lstnew(ft_strdup(str2));
// 	ft_lstadd_back(&lst1, lst2);
// 	printf("%s\n", (char *)lst1->content);
// 	printf("%s\n", (char *)lst1->next->content);
// 	tmp = lst1->next;
// 	ft_lstdelone(lst1, &del);
// 	printf("%s\n", (char *)tmp->content);
// }

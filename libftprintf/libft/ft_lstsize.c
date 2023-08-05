/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:41:21 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/15 13:37:02 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return ((int)size);
}

// int	main(void)
// {
// 	char	str1[] = "abcdefg";
// 	char	str2[] = "hijklmn";
// 	t_list	*lst;
// 	t_list	*new;
// 	int		size;

// 	lst = ft_lstnew(str1);
// 	new = ft_lstnew(str2);
// 	ft_lstadd_front(&lst, new);
// 	printf("%s\n", (char *)lst->content);
// 	printf("%s\n", (char *)lst->next->content);
// 	size = 0;
// 	size = ft_lstsize(lst);
// 	printf("%d\n", size);
// }

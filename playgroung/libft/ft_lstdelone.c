/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:28:47 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/25 02:12:52 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!!lst)
		return ;
	if (!del)
		del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew(strdup("Hello"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("world")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("!!")));
	printf("before : %s\n       : %p\n", lst->next->next->content, lst->next->next);
	ft_lstdelone(lst->next->next, &free);
	printf("after  : %s\n       : %p\n", lst->next->next->content, lst->next->next);
	return (0);
}
*/

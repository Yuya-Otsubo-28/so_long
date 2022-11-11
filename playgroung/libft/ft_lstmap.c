/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:43:30 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/05 11:19:35 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*list;

	if (!f || !lst)
		return (NULL);
	first = NULL;
	while (lst)
	{
		list = ft_lstnew((*f)(lst->content));
		if (!list)
		{
			while (first)
			{
				ft_lstclear(&first, del);
				return (NULL);
			}
			return (NULL);
		}
		ft_lstadd_back(&first, list);
		list = list->next;
		lst = lst->next;
	}
	return (first);
}

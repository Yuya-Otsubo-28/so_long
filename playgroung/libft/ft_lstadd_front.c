/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:46:01 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/25 02:10:04 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	lst = &new;
}
/*
int	main(void)
{
	t_list	**lst2;
	t_list	*new1 = NULL;


	lst2 = (t_list**)malloc(sizeof(t_list*) * 3);
	if (!lst2)
		return (0);
	*lst2 = ft_lstnew("Jhon");
	ft_lstadd_front(lst2, new1);
	printf("*lst2->content : %s\n", (*lst2)->content);
	printf("*lst2->next    : %p\n", (*lst2)->next);
	*lst2 = (*lst2)->next;
	printf("*lst2->content : %s\n", (*lst2)->content);
	printf("*lst2->next    : %p\n", (*lst2)->next);

	return (0);
}
*/

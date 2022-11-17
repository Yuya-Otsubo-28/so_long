/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:35:35 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/25 02:08:51 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	t_list	*ret;

	ret = ft_lstnew("Hello");
	free(ret);
	while(1);
}
*/
/*
int	main(void)
{
	t_list	*ret;

	ret = ft_lstnew("Hello");
	printf("ret->content : %s\n", ret->content);
	printf("ret->next : %p\n", ret->next);
	printf("ret : %p\n", ret);
	return (0);
}
*/

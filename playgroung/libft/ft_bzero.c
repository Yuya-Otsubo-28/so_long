/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:30:40 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/17 17:31:21 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	ft_memset(s, 0, n);
}

/*
int	main(void)
{
	char	s1[] = "Hello World";
	char	s2[] = "Hello World";

	bzero(s1, 3);
	ft_bzero(s2, 3);
	printf("origin : Hello World\n");
	printf("bzero : %c\n", s1[3]);
	printf("ft_bzero : %c\n", s2[3]);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:22:54 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/09 13:59:13 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void	*s, int	c, size_t	n)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (n > 0)
	{
		*a = (unsigned char)c;
		a++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char	s1[] = "Hello World";
	char	s2[] = "Hello World";

	memset(s1, 'a', 20);
	ft_memset(s2, 'a', 20);
	printf("origin : Hello World\n");
	printf("memset : %s\n", s1);
	printf("ft_memset : %s\n", s2);
	return (0);
}
*/

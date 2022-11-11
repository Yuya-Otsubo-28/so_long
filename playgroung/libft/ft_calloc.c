/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:14:44 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/18 13:35:21 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	mult_size;

	mult_size = count * size;
	if (count != 0)
	{
		if (mult_size / count != size)
			return (NULL);
	}
	if (mult_size == 0)
		mult_size = 1;
	p = malloc(mult_size);
	if (!p)
		return (NULL);
	ft_bzero(p, mult_size);
	return (p);
}
/*
int	main(void)
{
	int	*p;
	int	*q;
	size_t	count = 0;
	size_t	size = 2;

	p = (int *)calloc(count, size);
	q = (int *)ft_calloc(count, size);

	printf("\n---- p ----\n");
	printf("adress : %p\n", p);
	for (int i = 0; i < 12; i++)
		printf("p[%d] : %d\n", i, p[i]);
	printf("\n");
	printf("---- q ----\n");
	printf("adress : %p\n", q);
	for (int i = 0; i < 10; i++)
		printf("q[%d] : %d\n", i, q[i]);
	return (0);
}
*/

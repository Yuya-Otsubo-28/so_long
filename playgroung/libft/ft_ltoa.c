/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:00:23 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/05 11:32:28 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

static long	ft_expone(int base, int power)
{
	long	res;

	res = 1;
	while (power > 1)
	{
		res *= base;
		power--;
	}
	return (res);
}

static void	store(long n, char *res, long index, int i)
{
	int	tmp;

	tmp = 0;
	while (index != 0)
	{
		res[i++] = (n / index - tmp) + '0';
		tmp = n / index * 10;
		index = index / 10;
	}
	res[i] = '\0';
}

char	*ft_ltoa(long n)
{
	char	*res;
	int		i;
	long	index;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
	{
		res = ft_ltoa(LONG_MIN + 1);
		res[ft_strlen(res) - 1] += 1;
		return (res);
	}
	i = 0;
	res = (char *)malloc(sizeof(char) * (count_digit(n) + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[i++] = '-';
		n *= -1;
	}
	index = ft_expone(10, count_digit(n));
	store(n, res, index, i);
	return (res);
}	
/*
#include<stdio.h>
#include<limits.h>
int	main(void)
{
	long	n = LONG_MAX;
	long	m = LONG_MIN;

	printf("int  : %ld\n", n);
	printf("char : %s\n\n", ft_ltoa(n));
	printf("int  : %ld\n", m);
	printf("char : %s\n\n", ft_ltoa(m));
	return (0);
}
*/

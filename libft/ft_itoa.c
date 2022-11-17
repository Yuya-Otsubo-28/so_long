/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:08:30 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/30 12:10:50 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
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

static int	ft_expone(int base, int power)
{
	int	res;

	res = 1;
	while (power > 1)
	{
		res *= base;
		power--;
	}
	return (res);
}

static void	store(int n, char *res, int index, int i)
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

char	*ft_itoa(int	n)
{
	char	*res;
	int		i;
	int		index;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
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
int	main(void)
{
	int	n = 1234567890;
	int	m = INT_MAX;

	printf("int  : %d\n", n);
	printf("char : %s\n\n", ft_itoa(n));
	printf("int  : %d\n", m);
	printf("char : %s\n\n", ft_itoa(m));
	return (0);
}
*/

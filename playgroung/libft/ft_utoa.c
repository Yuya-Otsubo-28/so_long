/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:45:56 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/05 11:31:31 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_power(unsigned int un)
{
	unsigned int	res;

	res = 1;
	while (un / 10 > 0)
	{
		un = un / 10;
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

static void	store(unsigned int un, char *res, unsigned int powered_ten, int i)
{
	int	tmp;

	tmp = 0;
	while (powered_ten != 0)
	{
		res[i++] = (un / powered_ten - tmp) + '0';
		tmp = un / powered_ten * 10;
		powered_ten = powered_ten / 10;
	}
	res[i] = '\0';
}

char	*ft_utoa(unsigned int un)
{
	char			*res;
	int				i;
	unsigned int	powered_ten;

	if (un == 0)
		return (ft_strdup("0"));
	i = 0;
	res = (char *)malloc(sizeof(char) * (count_power(un) + 1));
	if (!res)
		return (NULL);
	powered_ten = ft_expone(10, count_power(un));
	store(un, res, powered_ten, i);
	return (res);
}

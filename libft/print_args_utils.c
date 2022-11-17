/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:40:14 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/05 18:42:53 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(void *arg)
{
	long	addr;
	char	*res;
	int		len;

	addr = (long)arg;
	res = ft_deci_to_hexa(addr);
	if (!res)
		return (-1);
	len = (int)ft_strlen(res);
	ft_putstr_fd("0x", 1);
	len += 2;
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}

int	print_decimal(int arg)
{
	char	*res;
	int		len;

	res = ft_itoa(arg);
	if (!res)
		return (-1);
	len = (int)ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}

int	print_unsigned_d(unsigned int arg)
{
	char	*res;
	int		len;

	res = ft_utoa(arg);
	if (!res)
		return (-1);
	len = (int)ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}

int	print_lower_hexa(unsigned int arg)
{
	char	*res;
	int		len;

	res = ft_deci_to_hexa((long)arg);
	if (!res)
		return (-1);
	len = (int)ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}

int	print_upper_hexa(unsigned int arg)
{
	char	*res;
	size_t	index;

	res = ft_deci_to_hexa((long)arg);
	if (!res)
		return (-1);
	index = 0;
	while (res[index] != '\0')
	{
		res[index] = ft_toupper(res[index]);
		index++;
	}
	ft_putstr_fd(res, 1);
	free(res);
	return (index);
}

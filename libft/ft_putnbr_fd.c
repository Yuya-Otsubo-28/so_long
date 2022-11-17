/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:57:02 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/01 11:43:57 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	digit;
	long long	l_n;

	digit = 1;
	l_n = (long long)n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n *= -1;
	}
	while (l_n / digit != 0)
	{
		if (l_n / (digit * 10) == 0)
			break ;
		digit *= 10;
	}
	while (digit != 0)
	{
		ft_putchar_fd((l_n / digit) % 10 + '0', fd);
		digit = digit / 10;
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 1);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:57:48 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/28 14:06:07 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while ((size_t)INT_MAX < len)
	{
		write(fd, s, INT_MAX);
		len -= INT_MAX;
		s += INT_MAX;
	}
	write(fd, s, len);
}
/*
int	main(void)
{
	ft_putstr_fd("Hello World\n", 1);
	return (0);
}
*/

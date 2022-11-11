/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:07:06 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/05 11:25:18 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *s, int n, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len > (size_t)n)
		len = (size_t)n;
	write(fd, s, len);
}

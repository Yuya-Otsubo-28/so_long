/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:05:21 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/07 19:34:08 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int	c)
{
	char	*p;
	char	tmp_c;

	tmp_c = c % 256;
	p = (char *)s;
	if (tmp_c == '\0')
		return (p + ft_strlen(p));
	while (*p)
	{
		if (*p == tmp_c)
			return (p);
		p++;
	}
	return (NULL);
}

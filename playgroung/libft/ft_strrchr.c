/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:28:23 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/24 15:46:19 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int	c)
{
	char	tmp_c;
	char	*p;

	p = NULL;
	tmp_c = c % 256;
	if (tmp_c == '\0')
	{
		p = (char *)s;
		return (p + ft_strlen(p));
	}
	while (*s)
	{
		if (*s == tmp_c)
			p = (char *)s;
		s++;
	}
	return (p);
}
/*
int	main(void)
{
	char	s[128] = "abcdefedcba";
	int		c = 'd';

	printf("string : %s\nchar   : %c\nresult : %s\n\n", s, c, ft_strrchr(s, c));
	printf("string : %s\nchar   : z\nresult : %s\n", s, ft_strrchr(s, 'z'));
	return (0);
}
*/

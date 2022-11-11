/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:06:43 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/23 22:53:24 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	if (!c && !n)
		return (NULL);
	if (c == '\0')
		return (tmp + ft_strlen((char *)tmp));
	while (n > 0)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	int		c = 2;
	size_t	n = 3;
	char	s1[] = {0, 1, 2, 3, 4, 5};
	char	s2[] = {0, 1, 2, 3, 4, 5};

	printf("\ns : %s\nn : %zu\nc : \'%c\'\n\n", s1, n, c);
	printf("---memchr---\n");
	printf("s : %s\n\n", memchr(s1, c, n));
	printf("--ft_memchr---\n");
	printf("s : %s\n\n", ft_memchr(s2, c, n));
	return (0);
}
*/

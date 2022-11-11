/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:58:51 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/17 09:53:57 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*tmp1 != *tmp2)
			return ((int)(*tmp1 - *tmp2));
		tmp1++;
		tmp2++;
		n--;
	}
	return (0);
}

/*
int	main(void)
{
	char	*s1 = "Hello\0Warld";
	char	*s2 = "Hello\0World";
	size_t	n = 10;

	printf("\ns1 : %s\ns2 : %s\nn : %zu\n\n", s1, s2, n);
	printf("---memcmp---\n");
	printf("result : %d\n\n", memcmp(s1, s2, n));
	printf("---ft_memcmp---\n");
	printf("result : %d\n\n", ft_memcmp(s1, s2, n));
	return (0);
}
*/

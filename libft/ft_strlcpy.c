/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:33:30 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/17 11:47:35 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	i = ft_strlen(src);
	if (n > 0)
	{
		while (*s != '\0' && n > 1)
		{
			*(dest++) = *(s++);
			n--;
		}
		*dest = '\0';
	}
	return (i);
}
/*
int	main(void)
{
	char	dest1[64];
	char	dest2[64];
	char	src[] = "";
	size_t	n = 9;
	size_t	n_dest1;
	size_t	n_dest2;

	printf("\ndest : %s\nsrc : %s\ndestsize : %d\n\n", dest1, src, (int)n);
	printf("---strlcat---\n");
	n_dest1 = strlcat(dest1, src, n);
	printf("dest : %s\nreturn : %d\n\n", dest1, (int)n_dest1);
	printf("---ft_strlcat---\n");
	n_dest2 = ft_strlcat(dest2, src, n);
	printf("dest : %s\nreturn : %d\n\n", dest2, (int)n_dest2);
	return (0);
}
*/

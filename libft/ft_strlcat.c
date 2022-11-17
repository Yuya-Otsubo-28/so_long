/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:17:02 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/18 13:05:50 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char	*s;
	size_t	dstsize;
	size_t	srcsize;
	size_t	total;

	srcsize = ft_strlen(src);
	if (n == 0)
		return (srcsize);
	dstsize = ft_strlen(dst);
	s = (char *)src;
	if (n > dstsize)
		total = dstsize + srcsize;
	else
		total = srcsize + n;
	while (n > dstsize + 1 && *s != '\0')
	{
		dst[dstsize] = *(s++);
		dstsize++;
	}
	dst[dstsize] = '\0';
	return (total);
}
/*
int	main(void)
{
	char	dest1[10] = "123456789";
	char	dest2[10] = "123456789";
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

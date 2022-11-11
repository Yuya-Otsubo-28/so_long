/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:26:09 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/17 17:31:40 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*adr_dst;
	unsigned char	*adr_src;

	if (!dest && !src)
		return (NULL);
	adr_dst = (unsigned char *)dest;
	adr_src = (unsigned char *)src;
	if (adr_dst > adr_src)
		while (len-- > 0)
			adr_dst[len] = adr_src[len];
	else
	{
		while (len > 0)
		{
			*(adr_dst++) = *(adr_src++);
			len--;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest1[] = "1234567890";
	char	dest2[] = "1234567890";
	char	dest3[] = "1234567890";
	char	dest4[] = "1234567890";
	char	dest5[] = "1234567890";
	char	dest6[] = "1234567890";
	char	src1[] = "abcdefghij";
	char 	src2[] = "abcdefghij";

	printf("dest : %s\n", dest1);
	printf("src  : %s\n\n", src1);
	printf("len  : %d\nres  : %s\n\n", 3, (char *)ft_memmove(dest2, src2, 3));
	printf("len  : %d\ndup1 : %s\n\n", 3, (char *)ft_memmove(dest3, &dest3[2], 3));
	printf("len  : %d\ndup2 : %s\n", 3, (char *)ft_memmove(&dest4[2], dest4, 3));
	printf("\n---  memmove ---\n");
	printf("len  : %d\ndup1 : %s\n\n", 3, (char *)memmove(dest5, &dest5[2], 3));
	printf("len  : %d\ndup2 : %s\n", 3, (char *)memmove(&dest6[2], dest6, 3));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:57:34 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/17 17:53:48 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!dest && !src)
		return (NULL);
	temp1 = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	while (n > 0)
	{
		*temp1 = *temp2;
		temp1++;
		temp2++;
		n--;
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
	printf("len  : %d\nres  : %s\n\n", 3, (char *)ft_memcpy(dest2, src2, 3));
	printf("len  : %d\ndup1 : %s\n\n", 3, (char *)ft_memcpy(dest3, &dest3[2], 3));
	printf("len  : %d\ndup2 : %s\n", 3, (char *)ft_memcpy(&dest4[2], dest4, 3));
	printf("\n---  memcpy ---\n");
	printf("len  : %d\ndup1 : %s\n\n", 3, (char *)memcpy(dest5, &dest5[2], 3));
	printf("len  : %d\ndup2 : %s\n", 3, (char *)memcpy(&dest6[2], dest6, 3));
	return (0);
}
*/
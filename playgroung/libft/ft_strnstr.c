/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:17:27 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/20 13:49:29 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size;

	if (*needle == '\0')
		return ((char *)haystack);
	size = ft_strlen(needle);
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (i < len && i < size && haystack[i] == needle[i])
				i++;
			if (i == size)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*haystack1 = "00123450987";
	char	*haystack2 = "00123450987";
	char	*needle = "1234";
	char	*res1;
	size_t	len = ft_strlen(haystack1);

	printf("\nhaystack : %s\nneedle : %s\nlen : %ld\n\n", haystack1, needle, len);
	res1 = strnstr(haystack1, needle, len);
	printf("---strnstr---\n");
	printf("result : %s\n\n", res1);
	printf("---ft_strnstr---\n");
	printf("result : %s\n\n", ft_strnstr(haystack2, needle, len));

	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:54:04 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/17 12:20:31 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	ssize;

	if (!s)
		return (NULL);
	ssize = ft_strlen(s);
	if (ssize < start)
		len = 0;
	else if (ssize - start < len)
		len = ssize - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i] && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
/*
int	main(void)
{
	char	s[] = "1234567890";
	
	printf("\nstring : %s\n\n", s);
	printf("start:%d\nlen:%d\nres : %s\n", 0, 22, ft_substr(s, 3, 9));
	return (0);
}
*/

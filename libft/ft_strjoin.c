/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:57:01 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/23 18:51:45 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	size_t	total_size;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s12 = (char *)malloc(sizeof (char) * total_size);
	if (!s12)
		return (NULL);
	while (*s1 != '\0')
		s12[i++] = *(s1++);
	while (*s2 != '\0')
		s12[i++] = *(s2++);
	s12[i] = '\0';
	return (s12);
}
/*
int	main(void)
{
	char	s1[] = "Hello ";
	char	s2[] = "World";

	printf("s1     : %s\n", s1);
	printf("s2     : %s\n", s2);
	printf("result : %s\n", ft_strjoin(s1, s2));
	return (0);
}
*/

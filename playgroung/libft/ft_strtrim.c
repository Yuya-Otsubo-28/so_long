/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:02:37 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/17 12:29:47 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	size;
	char	*res;

	if (!s || !n)
		return (NULL);
	size = ft_strlen(s);
	if (size >= n)
		res = (char *)malloc(sizeof(char) * (n + 1));
	else
		res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size && i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	j;
	size_t	trimmed_size;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && i < j)
		i++;
	while (ft_strchr(set, s1[j]) && j >= i)
		j--;
	trimmed_size = j - i + 1;
	if (i > j)
		trimmed = (char *)malloc(sizeof(char) * 1);
	else
		trimmed = ft_strndup(&s1[i], trimmed_size);
	if (!trimmed)
		return (NULL);
	trimmed[trimmed_size] = '\0';
	return (trimmed);
}
/*
int	main(void)
{
	char	s1[] = "12311312323113";
	char	set[] = "123";

	printf("string : %s\n", s1);
	printf("set    : %s\n", set);
	printf("result : %s\n",ft_strtrim(s1, set));
	return (0);
}
*/

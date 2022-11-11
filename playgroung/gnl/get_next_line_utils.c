/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:48:26 by yotsubo           #+#    #+#             */
/*   Updated: 2022/09/05 15:53:28 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strclen(const char *str, char c)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] != c && str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s12;
	size_t	total_size;
	int		i;

	s12 = NULL;
	if (!s1 && !s2)
		return (NULL);
	total_size = ft_strclen(s1, '\0') + ft_strclen(s2, '\0') + 1;
	s12 = (char *)malloc(sizeof (char) * total_size);
	if (!s12)
		return (NULL);
	i = 0;
	while (s1 && *s1 != '\0')
		s12[i++] = *(s1++);
	while (s2 && *s2 != '\0')
		s12[i++] = *(s2++);
	s12[i] = '\0';
	return (s12);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	ssize;

	ssize = ft_strclen(s, '\0');
	if (ssize <= start)
		len = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i] && j < len)
		substr[j++] = s[i++];
	while (j < len)
		j += 1;
	substr[j] = '\0';
	return (substr);
}

char	*ft_strchr(const char *s, int	c)
{
	char	*p;
	char	tmp_c;

	tmp_c = (char)c;
	p = (char *)s;
	if (tmp_c == '\0')
		return (p + ft_strclen(p, '\0'));
	while (p && *p)
	{
		if (*p == tmp_c)
			return (p);
		p++;
	}
	return (NULL);
}

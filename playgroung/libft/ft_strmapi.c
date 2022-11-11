/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:56:50 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/21 12:42:38 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/*
char	func(unsigned int i, char c)
{
	char	res;

	res = c + i;
	return (res);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	s[] = "abcdefghij";

	printf("string : %s\n", s);
	printf("result  : %s\n", ft_strmapi(s, func));
	return (0);
}
*/

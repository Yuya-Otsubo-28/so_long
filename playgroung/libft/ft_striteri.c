/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:57:22 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/20 13:45:26 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/*
void	func(unsigned int i, char *s)
{
	*s = i + '0';
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char	s[] = "abcdefghij";

	printf("before : %s\n", s);
	ft_striteri(s, func);
	printf("after  : %s\n", s);
	return (0);
}
*/

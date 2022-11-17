/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:01:04 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/17 09:54:30 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int	c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	int	c1 = 'b';
	int	c2 = 'A';
	int	c3 = '&';

	printf("\"b\" => %c\n", ft_toupper(c1));
	printf("\"A\" => %c\n", ft_toupper(c2));
	printf("\"&\" => %c\n", ft_toupper(c3));

	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:10:58 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/17 17:30:51 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_isascii(int	c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("--- isascii ---\n");
	printf("%d\n", isascii('a'));
	printf("%d\n", isascii('A'));
	printf("%d\n", isascii('1'));
	printf("%d\n", isascii('\n'));
	printf("%d\n", isascii(' '));
	printf("%d\n", isascii(''));
	printf("%d\n", isascii(3));
	printf("\n--- ft_isascii ---\n");
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", ft_isascii('1'));
	printf("%d\n", ft_isascii('\n'));
	printf("%d\n", ft_isascii(' '));
	printf("%d\n", ft_isascii(''));
	printf("%d\n", ft_isascii(3));
}
*/
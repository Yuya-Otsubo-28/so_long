/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:02:18 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/17 17:30:27 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isdigit(int	c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("--- isdigit ---\n");
	printf("%d\n", isdigit('a'));
	printf("%d\n", isdigit('A'));
	printf("%d\n", isdigit('1'));
	printf("%d\n", isdigit('\n'));
	printf("%d\n", isdigit(' '));
	printf("%d\n", isdigit(''));
	printf("%d\n", isdigit(3));
	printf("\n--- ft_isdigit ---\n");
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit('A'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isdigit('\n'));
	printf("%d\n", ft_isdigit(' '));
	printf("%d\n", ft_isdigit(''));
	printf("%d\n", ft_isdigit(3));
}
*/
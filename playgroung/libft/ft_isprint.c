/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:17:01 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/17 17:31:01 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(int	c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("--- isprint ---\n");
	printf("%d\n", isprint('a'));
	printf("%d\n", isprint('A'));
	printf("%d\n", isprint('1'));
	printf("%d\n", isprint('\n'));
	printf("%d\n", isprint(' '));
	printf("%d\n", isprint(''));
	printf("%d\n", isprint(3));
	printf("\n--- ft_isprint ---\n");
	printf("%d\n", ft_isprint('a'));
	printf("%d\n", ft_isprint('A'));
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint(''));
	printf("%d\n", ft_isprint(3));
}
*/
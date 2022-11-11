/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:06:04 by yotsubo           #+#    #+#             */
/*   Updated: 2022/05/17 17:30:44 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum(int	c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	printf("--- isalnum ---\n");
	printf("%d\n", isalnum('a'));
	printf("%d\n", isalnum('A'));
	printf("%d\n", isalnum('1'));
	printf("%d\n", isalnum('\n'));
	printf("%d\n", isalnum(' '));
	printf("%d\n", isalnum(''));
	printf("%d\n", isalnum(3));
	printf("\n--- ft_isalnum ---\n");
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_isalnum('\n'));
	printf("%d\n", ft_isalnum(' '));
	printf("%d\n", ft_isalnum(''));
	printf("%d\n", ft_isalnum(3));
}
*/
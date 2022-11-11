/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:52:42 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/02 01:30:54 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("--- isalpha ---\n");
	printf("%d\n", isalpha('a'));
	printf("%d\n", isalpha('A'));
	printf("%d\n", isalpha('1'));
	printf("%d\n", isalpha('\n'));
	printf("%d\n", isalpha(' '));
	printf("%d\n", isalpha(''));
	printf("%d\n", isalpha(3));
	printf("\n--- ft_isalpha ---\n");
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", ft_isalpha('\n'));
	printf("%d\n", ft_isalpha(' '));
	printf("%d\n", ft_isalpha(''));
	printf("%d\n", ft_isalpha(3));
}
*/

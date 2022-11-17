/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:53:54 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/18 13:36:04 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * "The functions atof, atoi, atol, and atoll need not affect the value of 
 * 
 * the integer expression errno on an error. If the value of the result
 *
 * cannot be represented, the behavior is undefined."
 *
 * ---ISO/IEC 9899;1999(E) 7.20.1 Numeric conversion functions
 * Rink : https://www.dii.uchile.cl/~daespino/files/Iso_C_1999_definition.pdf
 * 
 */

int	ft_atoi(const char *str)
{
	int	res;
	int	flag;
	int	i;

	flag = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			flag *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * flag);
}
/*
int	main(void)
{
	char	*str = "";

	printf("\nstr : %s\n\n", str);
	printf("---- atoi ----\n");
	printf("result : %d\n\n", atoi(str));
	printf("---- ft_atoi ----\n");
	printf("result : %d\n\n", ft_atoi(str));
	return (0);
}
*/

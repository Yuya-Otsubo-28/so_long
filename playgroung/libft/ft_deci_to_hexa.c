/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:53:45 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/05 11:27:45 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	store(char *res, int num_of_digit, unsigned long ln)
{
	int	index;

	index = 0;
	while (index < num_of_digit)
	{
		if (ln % 16 >= 10)
			res[num_of_digit - index++ - 1] = (char)(ln % 16 + ('a' - 10));
		else
			res[num_of_digit - index++ - 1] = (char)(ln % 16 + '0');
		ln = ln / 16;
	}
	res[index] = '\0';
}

char	*ft_deci_to_hexa(long ln)
{
	char			*res;
	int				num_of_digit;
	unsigned long	tmp;

	num_of_digit = 1;
	tmp = (unsigned long)ln;
	while (tmp / 16 != 0)
	{
		tmp = tmp / 16;
		num_of_digit++;
	}
	res = (char *)malloc(sizeof(char) * (num_of_digit + 1));
	if (!res)
		return (NULL);
	store(res, num_of_digit, ln);
	return (res);
}
/*
int main(void)
{
    long ln = 56789;
    char *res;

    res = ft_deci_to_hexa(ln);
    printf("%x\n%s\n", (unsigned int)ln, res);
    free(res);
    return (0);
}
*/

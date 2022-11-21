/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:33:29 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 17:45:40 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	s1_size;

	s1_size = ft_strlen(s1) + 1;
	cpy = (char *)malloc(sizeof (char) * s1_size);
	if (cpy == NULL)
		return (0);
	ft_strlcpy(cpy, s1, s1_size);
	return (cpy);
}

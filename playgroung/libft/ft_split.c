/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:26:55 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/21 10:40:52 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **hanger, size_t split_index)
{
	size_t	index;

	index = 0;
	while (index < split_index)
		free(hanger[index++]);
	free(hanger);
}

static size_t	split_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!ft_strchr(s, c) || !c)
		return (1);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	char_to_char_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

static char	**cut_s(char const *s, char c, size_t num_of_split, char **hanger)
{
	size_t	index_s;
	size_t	split_index;
	size_t	split_size;
	size_t	index;

	index_s = 0;
	split_index = 0;
	while (split_index < num_of_split)
	{
		while (s[index_s] == c && s[index_s] != '\0')
			index_s++;
		split_size = char_to_char_count(&s[index_s], c);
		hanger[split_index] = (char *)malloc(sizeof(char) * (split_size + 1));
		if (!hanger[split_index])
		{
			free_all(hanger, split_index);
			return (NULL);
		}
		index = 0;
		while (index < split_size)
			hanger[split_index][index++] = s[index_s++];
		hanger[split_index][index] = '\0';
		split_index++;
	}
	return (hanger);
}

char	**ft_split(char const *s, char c)
{
	char	**hanger;
	size_t	num_of_split;

	if (!s || !*s)
	{
		hanger = (char **)malloc(sizeof(char *) * 1);
		if (!hanger)
			return (NULL);
		hanger[0] = NULL;
		return (hanger);
	}
	num_of_split = split_count(s, c);
	hanger = (char **)malloc(sizeof(char *) * (num_of_split + 1));
	if (!hanger)
		return (NULL);
	if (!cut_s(s, c, num_of_split, hanger))
		return (NULL);
	hanger[num_of_split] = NULL;
	return (hanger);
}
/*
int	main(void)
{
	int		index;
	char 	**tab;

	tab = ft_split("aaaxxxbbb", 'x');
	index = 0;
	while (tab[index])
	{
		free(tab[index++]);
	}
	free(tab);
	system("leaks -q a.out");
	return (0);
}
*/
/*
int main(void)
{
    char    **hanger;
	int		i;

//	char * splitme = strdup("-12-345-6789");
	i = 0;
    hanger = ft_split("aaaxxbbb", 'x');
	while (hanger[i] != NULL)
	{
		printf("hanger[%d] : %s\n", i, hanger[i]);
		i++;
	}
	printf("hanger[0] : %s\n", hanger[0]);
	printf("hanger[1] : %s\n", hanger[1]);
	printf("hanger[2] : %s\n", hanger[2]);
	printf("hanger[3] : %s\n", hanger[3]);
	printf("hanger[4] : %s\n", hanger[4]);
	printf("hanger[5] : %s\n", hanger[5]);
//	printf("hanger[6] : %s\n", hanger[6]);
    return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:45:42 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 10:14:06 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	free_double_ptr_int(int **ptr, size_t count)
{
	size_t	i;

	i = 0;
	if (count < 1)
		return ;
	while (i < count)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_double_ptr(char **ptr, size_t count)
{
	size_t	i;

	i = 0;
	if (count < 1)
		return ;
	while (i < count)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void	print_error(int error_num)
{
	if (error_num == ARGS_ERROR)
		ft_putstr_fd("ERROR\n***argument***\n", STDERR_FILENO);
	if (error_num == FILENAME_ERROR)
		ft_putstr_fd("ERROR\n***filename***\n", STDERR_FILENO);
	if (error_num == INPUT_ERROR)
		ft_putstr_fd("ERROR\n***map***\n", STDERR_FILENO);
	if (error_num == MALLOC_ERROR)
		ft_putstr_fd("ERROR\n***malloc***\n", STDERR_FILENO);
	if (error_num == MLX_ERROR)
		ft_putstr_fd("ERROR\n***mlx***\n", STDERR_FILENO);
}

void	error_handle(int error_num, ...)
{
	va_list	ap;
	void	*tmp;

	va_start(ap, error_num);
	print_error(error_num);
	while (1)
	{
		tmp = va_arg(ap, void *);
		if (!tmp)
			break ;
		free(tmp);
	}
	exit(1);
}
/*
int main(void)
{
    int error_num = FILENAME_ERROR;
    char *str1;
    char *str2;

    str1 = (char *)malloc(sizeof(char) * 3);
    str2 = (char *)malloc(sizeof(char) * 4);
    error_handle(error_num, str1, str2, NULL);
    return (0);
}
*/

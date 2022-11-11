/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:51:13 by yotsubo           #+#    #+#             */
/*   Updated: 2022/07/07 15:04:51 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_to_percent(const char *format)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	return ((int)i);
}

int	print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	print_args(char *format, va_list ap)
{
	int	len;

	len = 0;
	if (format[1] == 'c')
		len = printf_putuchar_fd(va_arg(ap, int), 1);
	else if (format[1] == 's')
		len = printf_putstr_fd(va_arg(ap, char *), 1);
	else if (format[1] == 'p')
		len = print_pointer(va_arg(ap, void *));
	else if (format[1] == 'd' || format[1] == 'i')
		len = print_decimal(va_arg(ap, int));
	else if (format[1] == 'u')
		len = print_unsigned_d(va_arg(ap, unsigned int));
	else if (format[1] == 'x')
		len = print_lower_hexa(va_arg(ap, unsigned int));
	else if (format[1] == 'X')
		len = print_upper_hexa(va_arg(ap, unsigned int));
	else if (format[1] == '%')
		len = print_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		res;
	int		args_res;

	res = 0;
	va_start(ap, format);
	while (*format)
	{
		len = len_to_percent(format);
		ft_putnstr_fd((char *)format, len, 1);
		res += len;
		format += len;
		if (format[0] && format[1])
		{
			args_res = print_args((char *)format, ap);
			if (args_res < 0)
				return (-1);
			res += args_res;
			format += 2;
		}
	}
	va_end(ap);
	return (res);
}
/*
int main(void)
{
    ft_printf(" NULL %s NULL \n", NULL);
    return (0);
}
*/

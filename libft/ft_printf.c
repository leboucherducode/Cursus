/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <jeschwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:54:37 by jeschwar          #+#    #+#             */
/*   Updated: 2025/02/24 14:32:47 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_format(char format, va_list args, int count)
{
	if (format == 'c')
		count = count + ft_putchar(va_arg(args, int));
	else if (format == 's')
		count = count + ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count = count + ft_print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		count = count + ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count = count + ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count = count + ft_puthex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		count = count + ft_puthex(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		count = count + ft_putchar('%');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = ft_format(format[i + 1], args, count);
			i++;
		}
		else
			count = count + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

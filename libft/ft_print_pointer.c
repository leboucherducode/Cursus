/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <jeschwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:53:48 by jeschwar          #+#    #+#             */
/*   Updated: 2025/02/24 14:33:04 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
	{
		count = count + ft_printptr(ptr / 16);
		count = count + ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			count = count + ft_putchar(ptr + '0');
		else
			count = count + ft_putchar(ptr - 10 + 'a');
	}
	return (count);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = count + ft_putstr("0x");
	if (ptr == 0)
		return (ft_putchar('0'));
	count = count + ft_printptr((ptr));
	return (count);
}

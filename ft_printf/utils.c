/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:22:10 by jeschwar          #+#    #+#             */
/*   Updated: 2024/11/12 11:46:18 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	char	c;
	int		res;

	res = 0;
	if (nbr == -2147483648)
	{
		res = res + write (1, "-2147483648", 11);
		return (res);
	}
	if (nbr < 0)
	{
		res = res + write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		res = res + ft_putnbr(nbr / 10);
	}
	c = '0' + (nbr % 10);
	res = res + write (1, &c, 1);
	return (res);
}

int	ft_puthex(unsigned int nbr, char format)
{
	int		res;

	res = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			res = res + ft_putchar('0' + nbr);
		else
			res = res + ft_putchar(format + nbr - 10 - 23);
	}
	else
	{
		res = res + ft_puthex(nbr / 16, format);
		res = res + ft_puthex(nbr % 16, format);
	}
	return (res);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr >= 10)
		res = res + ft_putnbr_unsigned(nbr / 10);
	res = res + ft_putchar((nbr % 10) + '0');
	return (res);
}

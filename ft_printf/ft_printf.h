/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:42:37 by jeschwar          #+#    #+#             */
/*   Updated: 2024/11/12 13:23:01 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_puthex(unsigned int nbr, char format);
int	ft_puthex(unsigned int nbr, char format);
int	ft_print_pointer(unsigned long long ptr);
int	ft_printf(const char *format, ...);
#endif

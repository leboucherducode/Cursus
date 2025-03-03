/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcomp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:31:57 by jeschwar          #+#    #+#             */
/*   Updated: 2024/10/22 14:40:08 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *s, const void *d, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*des;

	i = 0;
	src = (unsigned char *)s;
	des = (unsigned char *)d;
	while (i != n)
	{
		if (src[i] != des[i])
		{
			return (src[i] - des[i]);
		}
		i++;
	}
	return (0);
}

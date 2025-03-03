/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:03:04 by jeschwar          #+#    #+#             */
/*   Updated: 2024/10/28 10:03:20 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	str = (char *)malloc(size_s1 + size_s2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size_s1 + size_s2 + 1);
	ft_strlcat(str, s2, size_s1 + size_s2 + 1);
	return (str);
}

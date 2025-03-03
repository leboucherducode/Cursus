/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:23:40 by jeschwar          #+#    #+#             */
/*   Updated: 2024/10/23 10:47:41 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;
	size_t	i;

	len = ft_strlen((char *)s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == 0)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}

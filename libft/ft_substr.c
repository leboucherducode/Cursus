/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <jeschwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:03:49 by jeschwar          #+#    #+#             */
/*   Updated: 2025/02/11 11:07:03 by jeschwar         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start + len > ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
